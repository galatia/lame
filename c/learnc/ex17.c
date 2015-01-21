#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// #define creates a macro: 2 args [NAME OF MACRO] [TEXT THAT MACRO TEXT REPLACES IT WITH]
// replacement only happens in compiler (so not a var); you can't reassign to it
// more efficient than var because doesn't take up space at runtime; no chance of cloberring (rewritten)
#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
  int  id;
  int  set;
  // can't use var instead of define because var is mutable
  // and need to have immutable sizeof(struct)
  char name[MAX_DATA];
  char email[MAX_DATA];
  // nb means the array is that length, but if not full, has '\0's after
}

// array of struct addresses
struct Database {
  struct Address rows[MAX_ROWS];
};

struct Connection {
  // Connection tells you how to do stuff with the db
  // FILE is actually int, i.e., a "file descriptor" 
      // e.g., stdout is file descriptor 1, stderror is 2, etc. 
  // each file you open gets a file descriptor
  // it's an opaque type, meaning you're not supposed to look at it
  // it's kinda like a pointer, but usually just the descriptor itself
  FILE *file;
  struct Database *db;
};

// const := not allowed to modify the memory that the pointer points to
// (confusing construction: doesn't apply to type "char"; rather to pointer; 
  // but not to pointer; rather to thing being pointed at)
// good practice to make const any *args that a function won't modify (then
    // compiler can optimize it; if it's not a pointer, it's copeid anyway)
void die(const char *message)
{
  // errno = error number; system calls set it to indicate the type of error
  if(errno) {
    // print current error i.e., decodes errno (prints human readable error +
    // string you pass into it)
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  // exit the entire program (tells kernel that the process wants to exit)
  exit(1);
}

// the reason why you take a pointer is because it is less memory than copying
// the entire struct (and less time to copy it)
// this is the general practice for structs as args for function
void Address_print(struct Address *addr)
{
  printf("%d %s %s\n", 
      addr -> id, addr -> name, addr -> email);
}

// Load the database from conn->file into conn->db; and die otherwise
void Database_load(struct Connection *conn)
{
  // fread returns number of bytes read; if error, returns 0
  // (void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
      // (ptr to store byte read = conn -> db,
      // each item read is size bytes long = sizeof(struct Database),
      // number of items to read = 1,
      // FILE to read from = conn -> file)
  int readcount = fread(conn -> db, sizeof(struct Database), 1, conn -> file);
  if(readcount != 1) die("Failed to load database");
}

// function that returns something of type struct Connection pointer
// mallocs the struct, which means when you call this you have to free later
struct Connection* Database_open(const char *filename, char mode)
{
  // the pointer to struct Connection goes to a malloc'ed block that size
  struct Connection *conn = malloc(sizeof(struct Connection));
  // die if there's not enough memory
  if(!conn) die("Memory error: can't malloc for conn");

  // set the db field (which is a pointer) to a malloc'ed block database size
  conn -> db = malloc(sizeof(struct Database));
  if(!conn -> db) die("Memory error");

  // mode for fopen
  if(mode == 'c') {
    conn -> file = fopen(filename, "w");
  } else {
    // reading and writing (beginning of file)
    conn -> file = fopen(filename, "r+");

    // also load the database
    if(conn -> file) Database_load(conn);
  }

  if(!conn -> file) die("Failed to open the file");

  return conn;
}

void Database_close(struct Connection *conn)
{
  if(conn) {
    // close the file
    if(conn -> file) fclose(conn -> file);
    // free conn->db
    if(conn -> db)   free  (conn -> db);
    free(conn);
  }
}

void Database_write(struct Connection *conn)
{
  // set file position indicator to the beginning of the file
  rewind(conn -> file);

  // writes stuff pointed at by conn->db, 
  // each the size of (struct Database), 1  of them, to conn->file
  int rc = fwrite(conn -> db, sizeof(struct Database), 1, conn -> file);
  // returns number of objects written, so if rc!=1, it failed
  if(rc != 1) die ("Failed to write database");

  // fflush forces a write to the file
  rc = fflush(conn -> file);
  if(rc == -1) die ("Cannot flush database");
}

void Database_create(struct Connection *conn)
{
  int i;
  for(i = 0; i < MAX_ROWS; i++)  {
    // make a prototype to initialize it
    struct Address addr = {.id = i, .set = 0};
    // then just assign it
    // get the i element of rows, which is in db, which is in conn, then get
    // the address of (&) it
    conn -> db -> rows[i] = addr;
  }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
  struct Address *addr = &conn -> db -> rows[id];
  if(addr -> set) die("Already set, delete it first");

  addr -> set = 1;
  // warning: bug
  char *res = strncpy(addr -> name, name, MAX_DATA);
  if(!res) die("Name copy failed");

  res = strncpy(addr -> email, email, MAX_DATA);
  if(!res) die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
  struct Address *addr = &conn -> db -> rows[id];

  if(addr -> set) Address_print(addr);
  else die("ID not set");
}

void Database_delete(struct Connection *conn, int id)
{
  struct Address addr = {.id = id, .set = 0}
  conn -> db -> rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
  int i;
  struct Database *db = conn -> db;

  for(i = 0; i < MAX_ROWS; i++) {
    struct Address *current = &db -> rows[i];

    if(current -> set) Address_print(current);

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if(argc > 3)         id = atoi(argv[3]);
    if(id   >= MAX_ROWS) die ("There's not that many records");

    switch(action) {
      
      case 'c': 
        Database_create(conn);
        Database_write(conn);
        break;

      case 'g':
        if(argc != 4) die("Need an id to get");

        Database_get(conn, id);
        break;

      case 's':
        if(argc != 6) die("Need id, name, email to set");

        Database_set(conn, id, argv[4], argv[5]);
        Database_write(conn);
        break;

      case 'd':
        if(argc != 4) die ("Need id to delete");

        Database_delete(conn, id);
        Database_write(conn);
        break;

      case 'l':
        Database_list(conn);
        break;
      
      default:
        die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
    }

    Database_close(conn);

    return 0;
  }

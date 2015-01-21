#include <stdio.h>
#include <assert.h> // assert
#include <stdlib.h> // malloc
#include <string.h> // strdup (cp string; first malloc then copies into that)

// Create the type; ie struct Person //
  // like a class or row of database table
struct Person {
  char *name;
  int   age;
  int   height;
  int   weight;
};

// FUNCTIONS to do with struct Person //

struct Person *Person_create(char *name, int age, int height, int weight) {
  // allocate memory: size of the type struct Person
  // memory has pointer "who" 
  // ie made a variable "who" that has that memory
  struct Person *who = malloc(sizeof(struct Person));
  // "who" is an arbitrary name and is local to this function so it doesn't matter

  // check that malloc didn't give invalid pointer
  assert(who != NULL);

// this instanct of struct Person -> attribute to set = whatever; 
  who -> name   = strdup(name);
  who -> age    = age;
  who -> height = height;
  who -> weight = weight;

  return who;
}

// Need a "destroy" for all "create"s
// otherwise you get a memory leak
void Person_destroy(struct Person *who) 
{
  // make sure the input is good
  assert(who != NULL);

  // need to free (who -> name) "individually" because of strdup; it's not just the pointer to the args
  free(who -> name);
  free(who);
}

void Person_print(struct Person *who)
{
  printf("Name: %s\n",     who -> name);
  printf("\tAge: %d\n",    who -> age);
  printf("\tHeight: %d\n", who -> height);
  printf("\tWeight: %d\n", who -> weight);
}

/////

int main(int argc, char **argv)
{
  // make 2 people stuctures
  struct Person *joe = Person_create(
      "Joe Alex", 32, 64, 140);

  struct Person *frank = Person_create(
      "Frank Blank", 20, 72, 180);

  //print them out and where they are in memory
  printf("Joe is at memory location %p:\n", joe);
  Person_print(joe);

  printf("Frank is at memory location%p:\n", frank);
  Person_print(frank);

  // make everyone age 20 years and print again
  joe -> age      += 20;
  joe -> height   -= 2;
  joe -> weight   += 40;

  frank -> age    += 20;
  frank -> weight += 20;

  Person_print(joe);
  Person_print(frank);

  // destroy them to clean up
  Person_destroy(joe);
  Person_destroy(frank);

  return 0;
}

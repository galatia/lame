#include <stdio.h>
#include <stdlib.h>

/* Remarks:
This is a linked list; i.e., each elem includes pointer for next
(as opposed to array, which auto incr to next pointer b/c in same block)
* is pointer 
  - pointers are always 8 bytes (64bit comp)
  - pointers are index into memory of some 
    object of their type 
* string is actually incrementing char* until 
  you hit *(char*) == 0, which means string is over
  ---> char is 1 byte; larger types are maybe more expensive
* you would use dict for struct in python
  --> has (two) keys (here) (ie s and next) 
  --> values aren't yet defined because just giving type
  ie BLAH :: struct node = {s: , next: } 
* a pointer can be 0 even though there is nothing at location 0; 
  it indicates None (nothing being pointed to in memory)
* need ; after defining data type, but not usually after }

General C remarks:
* you can't have nude code; must be in a function or a declaration

*/
struct node {
  int num; // str :: char* 
  struct node* next; // next :: node* 
                     // recursive, ie next is pointer to new struct node
                     // struct node has struct node* means 
                     // struct node has a pointer to a struct node (which can be not itself)
};

// print all the elements of a list :: struct node
//                  can write: struct node *lst
//                  *lst :: struct node therefore lst :: struct node*
//                  but instead, we say that lst just is :: struct node*
// we don't pass in the something of lst because it's bigger than just the pointer
// and it takes time to make a copy of lst to put in as an arg here
int sumLinkedList(struct node* lstPointer) { // ideally, node would be blue and italicized too
  int sum;
  /*for 
    (anything (executed once); 
    conditional (bool expr); -- tested each iter before exec for loop; breaks if false
    anything else (executed at the end of each iter)) */

  // &something == pointer (to something)
    // *pointer == something
    // *&something == something
  // for loops iterate on a iterator that must have a type
    // here it is of type pointer to struct node (i.e., struct node*) 

  // first: the first time, struct node* (ie pointerToSNode) is the arg you pass in (ie lstPointer)
  // conditional (before each iter):  
    // are there any more nodes or is the list empty
    // if the list is empty, the struct node* will be 0 because it was 
      // set to the previous struct node*'s next, which was like 
        // nope this one you just did is the last one, don't try to do it again
        // (or if you pass in 0 as lstPointer arg of fn)  
  // iter (before conditional after each iter): 
    // make the pointer you're going to be the pointer of the next of this node

  // != 0 is already false, so can just write without the != 0 
  for (struct node* pointerToSNode = lstPointer; pointerToSNode != 0; pointerToSNode = pointerToSNode -> next){
    // can say type of nextNum in same var assignment line
    // could also be num because num is a field so no conflict, 
    // but is nextNum for human clarity 
    int nextNum = pointerToSNode -> num;
    printf("%d\n", nextNum);
    sum += nextNum;
  }

  printf("%d\n", sum);

  return 0;
}

// write return type up front, ie int because return 0
int main(int argc, char **argv) { /* argc is length of list because
                                     doesn't know its length by itself
                                     but operating system passes it in for you;
                                     ** is pointer to a pointer for list of unknown 
                                     length of lists of unknown length of char */ 
  //printf("hello %s, goodbye %s\n", argv[1], argv[2]); // argv[0] is command (./hello)
  
  // Building the list:

  struct node* lst = 0; // lst :: struct node*, and lst = None
                        // (lst is a pointer (cuz of *) so contains index to mem which contains a struct node)
                        // as opposed to lst :: struct node 
                        // and in general struct is its own data type and isn't just pointer 
                        // (even if only contains pointer)
                          // because it is not a valid pointer, the last elem of list
                          // i.e., the first created stops the list from finding another element
  int i; // ie i is an int
  // needs to go backwards because otherwise list is backwards
  // because each time node added to list, is added at beginning (like Haskell)
  // starts at last elem of list; argv[0] is name of program so don't include i == 0
  for (i = argc - 1; i > 0; i--){
    /* malloc = memory allocate; 
      finds a region of unused memory at run time 
      (but actually whenever it hits a malloc)
      and then points to the beginning of that chunk 
      and this chunk is the number of bytes long that you passed in
      ie it allocates chunk the length you wanted
      (so newLst is a pointer too!)
    sizeof is sizeof data type (ie struct node) in bytes 
        // struct node as a data type has a set size (not specific one)
    sizeof is an operator, not function; eval at compile time
      ie no function call to sizeof in compiled code, just has the answer */
    // pointer to the struct node is a pointer to the beginning of 
    // a chunk of memory of size struct node
    // haven't initialized values inside of struct node (ie str and next)
    // so they are "anything" but probably 0
    // so the struct node exists even though its contents are not actually useful yet 
    struct node* newLst = malloc(sizeof(struct node)); 
    // -> dereferences the left
    // ie it goes to where the pointer points and grabs the value
    // ie also like lst[elem]
    // but actually -> gives an lvalue meaning you can assign things to it
    // so it doesn't actually grab thing, instead assigns 
    //  value to thing it would'be grabbed
    // actual character saved is the argv it's up to, 
    // then for that char, next points to the next node pair (s, next)
    // ... replace the value of the field in the struct (ie struct node) 
    //     pointed to by the pointer (ie newLst), because currently it's "anything"
    //     with the right side (ie lst for next and argv[i] for str)
    newLst -> next = lst; // var "next" in newLst is now equal to lst
                          // (newLst -> next) is set to lst, which is set to the previous 
                          // iter's newLst each time
    newLst -> num  = atoi(argv[i]); // atoi is like python int(); if float, int(floor()); else 0; 
    // changes value of lst to point to the same place as where newLst points
    // ie it changes pointer which is value of lst but not the value at the poiner lst holds 
    // ie doesnt have the node that is pointed to by newLst, just the pointer to it
    // it points for next iteration to the chunk of memory this iter allocated for newLst
    // so that it can use it for next so that it can find it 
    // because we're chaining the nodes backwards
    lst = newLst; // save this iter's newLst (ie pointer to struct node) as lst for next iter
  }

  sumLinkedList(lst);

  // TODO: Using the list (ie walk the pointer)

  // use a for loop to go from one element to the next

  return 0; //should return to terminate program
}
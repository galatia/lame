#include <stdio.h>

int main(int argc, char **argv)
{
  // creates 2 arrays
  int ages[] = {24, 43, 12, 89, 2};
       // need *names[] instead of **names
  char *names[] = {
    "Alan", "Frank", "mary", "john", "Lisa"
  };

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i;

  // first way using indexing
  // indexes of names and ages correspond
  // BACKWARDS: last elem is at count - 1 (because <); first is at 0
  for(i = count - 1; i >= 0; i--) printf("%s has %d years alive.\n", names[i], ages[i]);

  printf("---\n");

  // setup the pointers to the start of the arrays
  int *cur_age = ages;
       // char * is "pointer to char" ie string, but array of strings is pointer to pointer to char so needs char **
  char **cur_name = names;

  // 2nd way using pointers
  // it's an array of ints and *chars (ie strings) so the pointers are sequential; add 1 to get the next
  // get the thing the pointer refers to with *
       // *pointer == something
  for(i = 0; i < count; i++) 
    printf("%s is %d years old.\n", *(cur_name+i), *(cur_age+i));

  printf("---\n");

  // 3rd way, pointers are just arrays
  for(i = 0; i < count; i++) 
    printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);

  printf("---\n");

  // 4th way with pointers in a stupid complex way
  for(cur_name = names, cur_age = ages;
      (cur_age - ages) < count;
      cur_name++, cur_age++)
    printf("%s lived %d years so far.\n",
        *cur_name, *cur_age);

  printf("---\n");

  for(i = 0; i < count; i++)
    printf("%s is at pointer %p\n", names[i], &(names[i]));

  return 0;
}

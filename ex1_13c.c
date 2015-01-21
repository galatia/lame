#include <stdio.h>
#include <stdlib.h>

#define IN  1
#define OUT 2
#define MAX_WORD_LENGTH 100

void 
vertical_histogram(int bar_lengths[], int bar_count)
{
  // find the heighest bar count
  int i, max;
  max = 0;
  for (i = 1; i <= bar_count; i++) 
    if (bar_lengths[i] > max) 
      max = bar_lengths[i];

        // if doing a decrementing loop, you can use while instead of for
        // and it will go through until it's 0, then decrememnt after each loop
  for (int j = max; j > 0; j--){
    for (i = 1; i <= bar_count; i++)
      if (bar_lengths[i] >= j)  printf("#");
      else                      printf(" ");
    printf("\n");
  }

  for (i = 1; i <= bar_count; i++)
    printf("%d", i);
  printf("\n");
}


void
print_histogram(int bar_lengths[], int bar_count)
{
  for(int i = 1; i <= bar_count; i++) {
    printf("%3d ", i);
    for(int j = 0; j < bar_lengths[i]; j++)  printf("#");
    printf("\n");
  }
}


/* count lengths of words and call print_histogram on arr of counts of word
 * lengths*/
int 
main()
{
  int c, word_count, state, word_number, letter_count, max_length; 

  state = OUT;
  word_number = letter_count = max_length = 0;
  
  // find length of each word
  int length_counts[MAX_WORD_LENGTH];
  state = OUT;
  while((c = getchar()) != EOF){
    if (c == ' ' || c == '\n' || c == '\t'){
      state = OUT; 
      ++length_counts[letter_count];
      if (letter_count > max_length)  max_length = letter_count;
      letter_count = 0;
    } else if (state == OUT) {
      state = IN;
      ++letter_count;
    } else {
      ++letter_count;
    }
  }

  vertical_histogram(length_counts, max_length);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define IN  1
#define OUT 2
#define MAX_WORD_LENGTH 100

/* take arr of ints, the size of the number of words, with each element the
 * length of the word, and print a line of #'s 
 * nb starts at 1 */
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

  print_histogram(length_counts, max_length);

  return 0;
}

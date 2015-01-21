#include <stdio.h>
#include <stdlib.h>

#define IN  1
#define OUT 2

/* take arr of ints, the size of the number of words, with each element the
 * length of the word, and print a line of #'s */
void
print_histogram(int word_lengths[], int word_count)
{
  for(int i = 0; i < word_count; i++) {
    for(int j = 0; j < word_lengths[i]; j++)  printf("#");
    printf("\n");
  }
}

/* count lengths of words and call print_histogram on arr of lengths of words*/
int 
main()
{
  int c, word_count, state, word_number, letter_count; 

  state = OUT;
  word_count = word_number = letter_count = 0;
  
  // find how many words
  while((c = getchar()) != EOF) 
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      word_count ++;
    }

  // find length of each word
  int* word_lengths = malloc(sizeof(int)*word_count);
  state = OUT;
  while((c = getchar()) != EOF){
    if (c == ' ' || c == '\n' || c == '\t'){
      state = OUT; 
      word_lengths[word_number] = letter_count;
      word_number++; 
      letter_count = 0;
    } else if (state == OUT) {
      state = IN;
      letter_count++;
    }
  }

  print_histogram(word_lengths, word_count);
  free(word_lengths);

  return 0;
}

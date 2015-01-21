#include <stdio.h>

#define EACH_BAR for(i = 0; i < bar_count; i++)

void 
vertical_histogram(int* bar_lengths, int bar_count)
{
  // find the heighest bar count
  int i, max;
  max = 0;
  EACH_BAR
    if (bar_lengths[i] > max) 
      max = bar_lengths[i];

        // if doing a decrementing loop, you can use while instead of for
        // and it will go through until it's 0, then decrememnt after each loop
  for (int j = max; j > 0; j--){
    EACH_BAR
      if (bar_lengths[i] >= j)  printf("#");
      else                      printf(" ");
    printf("\n");
  }

  for (i = 1; i <= bar_count; i++)
    printf("%c", i+'a'-1);
  printf("\n");
}

int
main()
{
  int c;
  static const int nchars = 'z'-'a'+1;
  int char_frequencies[nchars] = {0};

  while ((c = getchar()) != EOF){
    if (c >= 'A' && c <= 'Z')  c += ('a'-'A');
    char_frequencies[c-'a']++;
  }

  vertical_histogram(char_frequencies, (nchars));
  
  return 0;
}

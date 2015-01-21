#include <stdio.h>

/* print char if it's not whitespace */

int
main()
{
  int c;

  while ((c = getchar()) != EOF)
    if (!(c == ' ' || c == '\n' || c == '\t')) putchar(c);
  return 0;
}

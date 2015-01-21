#include <stdio.h>

/* count digits, white space, others */

int
main()
{
  int c, i;
  int nwhite = 0, nother = 0;
  int ndigit[10];

  for (i = 0; i < 10; i++)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF)
                                                 // num is c-'0'
         if (c >= '0' && c <= '9'              )  ++ndigit[c-'0'];
    else if (c == ' ' || c == '\n' || c == '\t')  ++nwhite;
    else                                          ++nother;

  printf("Digits:\n");
  for (i = 0; i < 10; i++)  printf("\t%d\t%d\n", i, ndigit[i]);
  printf("Whitespace = %d\n Other = %d\n", nwhite, nother);

  return 0;
}

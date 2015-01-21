#include <stdio.h>

/* count chars in input*/

/*
int main() 
{
  long nc = 0;
  while (getchar() != EOF) 
    nc++;
  printf("%ld\n", nc);
  return 0;
}
*/

int main() 
{
  double nc; 
  for (nc = 0; getchar() != EOF; nc++);
  printf("%.0f\n", nc);
  return 0;
}

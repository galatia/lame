#include <stdio.h>
#include <stdlib.h>

// power function, raise int m to int>0 n
int 
power(int m, int n)
{
  int power = 1;
  while (n >= 1){
    power = power * m;
    n--;
  }
  return power;
}

int 
main()
{
  int* m, n;
  scanf("%d %d", m, n);

  int answer = power(&m, &n);
  printf("%d\n", answer);

  /*
  int i;
  for (i = 0; i < 10; i++)
    printf("%d %d %d\n", i, power(2,i), power(-3,i));
  */

  return 0;
}

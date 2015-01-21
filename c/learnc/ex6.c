#include <stdio.h>

int main(int argc, char **argv) {
  int distance = 100;
  float power = 2.345f;
  double super_power = 56789.4532;
  char initial = 'A';
  char first_name[] = "zed";
  char last_name[] = "shaw";

  printf("%d %f %f %c %s %s %s %c %s\n", distance, power, super_power, initial, first_name, last_name, first_name, initial, last_name);

  printf("");
  
  return 0;
}

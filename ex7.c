#include <stdio.h>

int main(int argc, char **argv) {
  int bugs = 100;
  double bug_rate = 1.2;

  // long is for storing big ints (32bits+)
  long universe_of_defects = 1L * 1024L * 1024L * 1024L;
  printf("The enire universe has %ld bugs.\n", universe_of_defects); //%ld is for long decimal

  double expected_bugs = bugs * bug_rate;
  printf("You are expected to have %f bugs.\n", expected_bugs);

  double part_of_universe = expected_bugs / universe_of_defects;
  printf("That is only a %e portion of the universe.\n", part_of_universe);

  // this is a demo of something weird
  char nul_byte = '\0';
  int care_percentage = bugs * nul_byte;
  printf("Which means you should care %d%%.\n", nul_byte, care_percentage); //%% is for printing '%'

  return 0;
}

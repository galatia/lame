#include <stdio.h>
#define MAXLINE 1000

// read a line (up to max length lim) into s, return length
int
getnextline(char s[], int lim) {
  int c, i;

  // until it's at max length, or EOF, or newline
  for (i = 0; i <= lim && (c=getchar())!=EOF && c!='\n'; i++)
    // save it in s
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

// copy 'from' into 'to', if 'to' is big enough
void
copy (char to[], char from[]) {
  int i = 0;
  // set to[i] the same as from[i], as long as it's not the end
  while ((to[i] = from[i]) != '\0')
    i++;
}

int
main() {
  int cur_length, max_length;                // current and max line lengths
  char cur_line[MAXLINE], max_line[MAXLINE]; // current and max lines

  max_length = 0;
  // set cur_length to the length of cur_line, using getnextline, as long as
  // not 0, ie there is a nextline
  while ((cur_length = getnextline(cur_line, MAXLINE)) > 0)
    if (cur_length > max_length) {
      max_length = cur_length;
      copy(max_line, cur_line);
    }
  if (max_length > 0) // ie, as long as there is any line at all
    printf("%s", max_line);
  return 0;
}

/*
void
longest_line(char** lines)
{
  while(there's another line)
    if(current_line > max_line_length){
      max_line = current_line;
      max_line_length = ;
    }
  printf("%s\n", max_line);
}    

int
main()
{
  int lines;
  longest_line(lines);
  return 0;
}
*/

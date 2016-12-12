#include <stdio.h>

int main()
{
  int c;
  int nc, tc, bc;

  nc = tc = bc = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      ++nc;
    if (c == '\t')
      ++tc;
    if (c == ' ')
      ++bc;
  }

  printf("\n");
  printf("%8s :\t%4d\n", "newlines", nc);
  printf("%8s :\t%4d\n", "tabs", tc);
  printf("%8s :\t%4d\n", "blanks", bc);
  printf("\n");
}

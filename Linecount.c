#include <stdio.h>

int main()
{
  int c;
  long lc;

  lc = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      ++lc;
  printf("\n%ld\n", lc);
}

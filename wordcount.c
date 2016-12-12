#include <stdio.h>

#define IN   1
#define OUT  0

int main()
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%5s %5s %5s\n", "Lines", "Words", "Chars");
  int i;
  for (i = 0; i<17; ++i) /* 3x5chars + blanks = 17 */
    printf("=");
  printf("\n");
  printf("%5d %5d %5d\n", nl, nw, nc);
}

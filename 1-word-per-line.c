#include <stdio.h>

#define IN  1
#define OUT 0

int main()
{
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (state == IN && (c == ' ' || c == '\n' || c == '\t')) {
      state = OUT;
      printf("\n");
    }
    else if (c == ' ' || c == '\n' || c == '\t')
      ;
    else {
      state = IN;
      putchar(c);
    }
  }
}

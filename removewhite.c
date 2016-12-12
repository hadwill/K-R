#include <stdio.h>
#define IN  1
#define OUT 0

int main()
{
  int c;
  int state;

  state = OUT;

  while ((c = getchar()) != EOF) {
    if (state == OUT) {
      if (c == ' ')
	;
      else {
	state = IN;
	putchar(c);
      }
    }
    else {
      if (c == ' ') {
	state = OUT;
	putchar(c);
      }
      else
	putchar(c);
    }
  }
}

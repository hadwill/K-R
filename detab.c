#include <stdio.h>

#define TAB     8

int main()
{
  int c, i, cols, blanks;

  cols = blanks = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      cols = blanks = 0;
      printf("\n");
    }
    else if (c == ' ') {
      ++cols;
      ++blanks;
    }
    else if (c == '\t') {
      for (i = 0; i < blanks; ++i)
	printf(" ");
      for (i = 0; i < TAB - (cols % TAB); ++i)
	printf(" ");
      cols = cols - (cols % TAB) + TAB;
      blanks = 0;
    }
    else {
      if (blanks != 0) {
	for (i = 0; i < blanks; ++i)
	  printf(" ");
	blanks = 0;
      }
      ++cols;
      putchar(c);
    }
  }
  return 0;
}

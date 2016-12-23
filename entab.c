#include <stdio.h>

#define TAB 8

int main()
{
  int c, i, cols, blanks, tabs;

  cols = blanks = tabs = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      cols = blanks = tabs = 0;
      printf("\n");
    }
    else if (c == ' ') {
      ++cols;
      ++blanks;
    }
    else if (c == '\t') {
      if (cols % TAB != 0) {
	cols = cols - (cols % TAB) + TAB;
	blanks = 0;
	++tabs;
      }
      else {
	cols = cols + TAB;
	++tabs;
      }
    }
    else {
      for (i = 0; i < tabs; ++i)
	printf("\t");
      if (blanks != 0) {
	for (i = 0; i < blanks / TAB; ++i)
	  printf("\t");
	if (blanks % TAB != 0)
	  for (i = 0; i < blanks % TAB; ++i)
	    printf(" ");
      }
      blanks = tabs = 0;
      putchar(c);
    }
  }
  return 0;
}


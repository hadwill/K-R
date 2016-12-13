#include <stdio.h>

#define IN  1
#define OUT 0
#define MAXLENGTH 30

int main()
{
  int c, state, i, j, nchar;
  int wlength[MAXLENGTH];

  state = OUT;
  for (i = 0; i <= MAXLENGTH; ++i)
    wlength[i] = 0;
  nchar = 0;

  while ((c = getchar()) !=EOF) {
    if  (state == IN && (c == ' ' || c == '\t' || c == '\n')) {
      state = OUT;
      ++wlength[nchar - 1];
      nchar = 0;
    }
    else if (state == IN)
      ++nchar;
    else if (state == OUT && (c == ' ' || c == '\t' || c == '\n'))
      ;
    else {
      state = IN;
      ++nchar;
    }
  }
  
  for (i = 0; i<= MAXLENGTH; ++i) {
    printf("\n%2d-letter words |", i+1);
    for (j = 1; j <= wlength[i]; ++j)
      printf("=");
  }
  printf("\n");
}

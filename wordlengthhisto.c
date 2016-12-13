#include <stdio.h>

#define IN  1
#define OUT 0
#define MAXLENGTH 30

/* This program suffers from poor internationalization : accented letters are counted twice. */
/* TODO : Make it nicer with separate functions. */

int main()
{
  int c, state, i, j, nchar, maxfreq;
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
  /* Horizontal histogram  */
  /*
  for (i = 0; i<= MAXLENGTH; ++i) {
    printf("\n%2d-letter words |", i+1);
    for (j = 1; j <= wlength[i]; ++j)
      printf("=");
  }
  printf("\n");
  */

  /* Vertical Histogram */
  /* First, find the most frequent word-length in order to get an idea about the height of the graph */
  maxfreq = 0;
  for (i = 0; i <= MAXLENGTH; ++i)
    if (wlength[i] > maxfreq)
      maxfreq = wlength[i];

  /* Make the ordinate and the  points */
  for (i = maxfreq; i >= 1; --i) {
    printf("%2d |", i);
    for (j = 0; j <= MAXLENGTH; ++j) {
      if (wlength[j] < i)
	printf("   ");
      else {
	--wlength[j];
	printf(" x ");
      }
    }
    printf("\n");
  }
  
  /* Make a pretty abscissa */
  printf("   +"); /* 3 blanks */
  for (i = 0; i <= MAXLENGTH; ++i)
    printf("---");
  printf("\n");
  printf("    ");
  for (i = 0; i <= MAXLENGTH; ++i)
    printf("%2d ", i + 1);
  printf("\n");
}

#include <stdio.h>

#define CHARVALS 94 /* ASCII codes 033 through 126 */

/* Print a histogram of the frequency of different characters in the input */

int main()
{
  int c, i, j;
  int freqs[CHARVALS];

  for (i = 0; i <= CHARVALS; ++i)
    freqs[i] = 0;

  while ((c = getchar()) != EOF)
    if (c>= 33 || c <= 126)
      ++freqs[c - 33];

  printf("\n");
  for (i = 0; i < CHARVALS; ++i) {
    printf("%c |", i + 33);
    for (j = 0; j < freqs[i]; ++j)
      printf("=");
    printf("\n");
  }
}

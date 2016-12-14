#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */
float conv(int t);

int main()
{
  int fahr;

  printf("%4s\t%6s\n", "fahr", "C");

  int i;
  for (i = 0; i < 14; ++i) /* 4 chars + 1 tab + 6 chars */
    printf("=");
  printf("\n");

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%4d\t%6.2f\n", fahr, conv(fahr));

  return 0;
}

float conv(int temp)
{
  float c;
  c = (5.0 / 9.0) * (temp-32);
  return c;
}
    

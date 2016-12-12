#include <stdio.h>

#define LOWER -40
#define UPPER 300
#define STEP  20

int main()
{
  float celsius, fahr;

  printf("%3s\t%6s\n", "C", "Fahr");

  int i;
  for (i = 0; i < 14; ++i) /* 3 chars + 1 tab + 6 chars */
    printf("=");
  printf("\n");

  for (celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP)
    printf("%3.0f\t%6.2f\n", celsius, 32.0 + ((9.0/5.0) * celsius));
}

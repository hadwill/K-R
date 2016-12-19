#include <stdio.h>
#define MAXLINE 1000 /* Starting at MAXLINE chars (including \n), lines won't be printed */

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline1(void);
void copy(void);

int main()
{
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getline1()) > 0)
    if (len > max) { /* The first of all longest lines will be printed */
      max = len;
      copy();
    }
  if (max > 0)
    printf("%s", longest);
  return 0;
}


int getline1(void)
{
  int c, i;
  extern char line[];
  
  for (i = 0; i < MAXLINE - 1
	 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy(void)
{
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}


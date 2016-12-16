#include <stdio.h>

#define MINLINE 80
#define MAXLINE 1000

int getline1(char line[], int maxline);

int main()
{
  int max, len;
  char line [MAXLINE];

  while ((len = getline1(line, MAXLINE)) > 0)
    if (len > MINLINE+1)
      printf("%s", line);

  return 0;
  
}

int getline1(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

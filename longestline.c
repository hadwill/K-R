#include <stdio.h>
#define MAXLINE 4

int getline1(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getline1(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) {
    printf("%d\n", max);
    printf("%s\n", longest);
  }
  return 0;
}

int getline1(char s[], int lim)
{
  int c, i;

  for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim)
      s[i] = c;
    else
      ;
  }

  if (c == '\n') {
    if (i < lim) {
      s[i] = c;
      ++i;
    }
    else
      ++i;
  }
  if (i > lim)
    s[lim] = '\0';
  else s[i] = '\0';
  return i;
}

void copy(char  to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}


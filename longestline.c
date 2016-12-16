#include <stdio.h>
#define MAXLINE 4 /* Starting at MAXLINE chars (including \n), lines won't be printed */

int getline1(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int c;
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getline1(line, MAXLINE)) > 0) {
    if (line[len-1] == '\n') {
      if (len > max) {
  	max = len;
	copy(longest, line);
      }
    }
    else {
      while ((c = getchar()) != EOF && c != '\n')
	++len;
      ++len;
      if (len > max)
	max = len;
    }
  }
  if (max > 0) {
    if (max < MAXLINE)
      printf("%s", longest);
    else
      printf("%d\n", max);
  }
  return 0;
}


int getline1(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) !=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char  to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}


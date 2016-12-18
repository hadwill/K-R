#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[], char to[], int lens);
int getline1(char line[], int maxline);

int main()
{
  int len;
  char line [MAXLINE];

  while ((len = getline1(line, MAXLINE)) > 0) {
    char to[len];
    reverse(line, to, len);
    printf("%s", to);
  }
  return 0;
}

int getline1(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c=getchar())!=EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void reverse(char from[], char to[], int lenfrom)
{
  int c, i;
  
  if (from [lenfrom-1] == '\n') {
    for (i = 0; i<= lenfrom-2; ++i)
      to[i] = from[(lenfrom-2)-i];
    to[lenfrom-1] = '\n';
  }
  else
    for (i = 0; i <= lenfrom-1; ++i)
      to[i] = from[(lenfrom-1)-i];
  to[lenfrom] = '\0';
  
}

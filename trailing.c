#include <stdio.h>

#define MAXLINE 30
#define IN 1
#define OUT 0

int getline1(char line[], int maxline);

int main()
{
  int len;
  char line[MAXLINE];
  while ((len = getline1(line, MAXLINE)) > 0)
    if (len > 1)
      printf("%s", line);
}

int getline1(char s[], int lim)
{
  int lastnw, c, i, state;
  state = OUT;
  lastnw = 0;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (c == ' ' || c == '\t') {
      s[i] = c;
      if (state == IN)
	state = OUT;
    }
    else {
      lastnw = i;
      s[i] = c;
      if (state == OUT)
	state = IN;
    }
  }
  if (c == '\n') {
    if (lastnw+1 < i)
      i = lastnw + 1;
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

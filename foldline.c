#include <stdio.h>

#define MAXLENGTH 81 /* 81 = 80 non-nl chars + '\n' + '\0' */
#define MAXLINE 1000
#define IN 1
#define OUT 0
#define TAB 8

int getline1(char line[], int maxline);
char show[MAXLENGTH];

int main()
{
  int len, i, j, k, col;
  char line[MAXLINE];
  extern char show[MAXLENGTH];

  col = 0;
  while((len =  getline1(line, MAXLINE)) > 0)
    for(i = 0; i <= len-2; i = i + MAXLENGTH-1) {
      for(j = 0; j <= MAXLENGTH; ++j)
	show[j] = 0;
      for(j = 0; j <= MAXLENGTH-2; ++j)
        show[j] = line[i+j];
      show[MAXLENGTH-1] = '\n';
      show[MAXLENGTH] = '\0';
      printf("%s", show);
      /* printf("%d", len); */
    }
  return 0;
}

  
int getline1(char s[], int lim)
/*
   Returns the length of the line, stripped out of its trailing whitespace
   It also replaces tabs with blanks.
*/
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

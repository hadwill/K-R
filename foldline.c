#include <stdio.h>

#define MAXLENGTH 20 /* 81 = 80 non-nl chars + '\n' + '\0' */
#define MAXLINE 1000
#define TAB 8

int getline1(char line[], int maxline);
void copy(char s[], int strl);

char show[MAXLENGTH];



int main()
{
  int len;
  char line[MAXLINE];

  while((len =  getline1(line, MAXLINE)) > 0)
    copy(line, len);

  return 0;
}



void copy(char s[], int l)
{
  int i, j, k, col, mod;

  extern char show[MAXLENGTH];

  col = 0;
  for(i = 0; i <= l-2; i = i + col) {
    for(j = 0; j <= MAXLENGTH; ++j)
      show[j] = 0;
    j = col = 0;
    while(col <= MAXLENGTH-2) {
      if (s[i+j] == '\t') {
	mod = TAB - (col % TAB);
	for (k = 0; k < mod; ++k) {
	  show[col] = ' ';
	  ++col;
	}
	++j;
      }
      else {
	show[col] = s[i+j];
	++col;
	++j;
      }
    }
    show[col] = '\n';
    show[col + 1] = '\0';
    printf("%s", show);
  }
}
      


int getline1(char s[], int lim)
/*
   Returns the length of the line, stripped out of its trailing whitespace
*/
{
  int lastnw, c, i, j;
  lastnw = 0;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (c == ' ' || c == '\t')
      s[i] = c;
    else {
      lastnw = i;
      s[i] = c;
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

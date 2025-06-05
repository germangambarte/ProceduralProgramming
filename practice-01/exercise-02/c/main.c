#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>
#define N 30

void load(char *x)
{
  printf("ingrese un text: ");
  fgets(x, sizeof(char) * 30, stdin);
}

void replace(char *x)
{
  for (int i = 0; x[i] != '\0'; i++)
    if (x[i] == '0')
    {
      x[i] = '2';
    }
}

void cutText(char *a, char *b){
  strcpy(b);
}

void main()
{
  char text[N];
  char copy[N];
  load(text);
  printf(text);
  replace(text);
  printf(text);
}
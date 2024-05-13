#include <stdio.h>
#include <string.h>

const int N = 100;

void load(char t[N])
{
  printf("Ingrese una frase\n");
  fgets(t,N,stdin);
}

void replace(char t[N])
{
  for (int i = 0; i < strlen(t); i++)
  {
    if(t[i] == '2')
    {
      t[i] = '0';
    }
  }
  printf("%s\n",t); 
}

void word_copy(char t[N], char c[12])
{
  strncpy(c,t,12);
  printf("%s\n",c);
}

void vowels_counter(char t[N])
{
  int count = 0;
  for(int i = 0; i < strlen(t);i++)
  {
    if( t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u' 
     || t[i] == 'A' || t[i] == 'E' || t[i] == 'I' || t[i] == 'O' || t[i] == 'U')
    {
      count = count + 1;
    }
  }
  printf("la frase tiene %d vocales\n",count);
}

int main()
{
  char text[N], copy[12];
  load(text);
  replace(text);
  word_copy(text,copy);
  vowels_counter(text);
}

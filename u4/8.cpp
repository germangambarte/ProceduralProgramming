#include <stdio.h>
#include <string.h>
#define N 24

void carga(char c[N], int i)
{
	printf("palabra: ");
	gets(c);
}

void palindromo(char c[])
{
	int ultimocaracter= strlen(c) - 1;
	char xc[N];

	if (strlen(c) < 2)
	{
		printf("La cadena es un palindromo\n");
		return;
	}

	if(c[0] != c[ultimocaracter])
	{
		printf("sizeof cadena: %d\n", strlen(c));
		printf("cadena: %s\n", c);
		printf("pc: %c\n", c[0]);
		printf("uc: %c\n", c[ultimocaracter]);
		printf("La cadena no es un palindromo\n");
		return;
	} else {
		strncpy(xc,&c[1], ultimocaracter - 1);
		printf("xc: %s\n", xc);
		palindromo(xc);
	}






}

int main()
{
	char cadena[N];
	int i = 0;
	printf("-----CARGA-----\n");
	carga(cadena,i);
	printf("-----PALINDROMO-----\n");
	palindromo(cadena);
	return 0;
}
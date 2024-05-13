#include <stdio.h>
#include <string.h>
#define LENGTH 24
#define CANTCAT 3
#define CANTSEC 5

void carga(
	float t[CANTCAT][CANTSEC],
	char c[CANTCAT][LENGTH],
	char s[CANTSEC][LENGTH]
	)
{
	for (int i = 0; i < CANTCAT; ++i)
	{
		printf("categoria: %s\n", c[i]);
		for (int j = 0; j < CANTSEC; ++j)
		{
			printf("%s: ",s[j]);
			scanf("%f", &t[i][j]);
		}
		printf("\n");
	}
}

int buscar_categoria(char c[CANTCAT][LENGTH], char cat[])
{
	int i = CANTCAT - 1;
	while(i > 0)
	{
		if(strcmp(c[i], cat) == 0) return i;
		i-=1;
	}

	return i;
}

void total_categoria(
	float t[CANTCAT][CANTSEC],
	char c[CANTCAT][LENGTH]
	)
{
	char cat[LENGTH];
	int i;
	float sum = 0;

	printf("categoria: \n");
	fflush(stdin);
	gets(cat);

	i = buscar_categoria(c,cat);

	if(i == -1)
	{
		printf("categoria no encontrada\n");
		return;
	}

	for (int j = 0; j < CANTSEC; ++j)
	{
		sum += t[i][j];
	}

	printf("total financiado de %s: %.2f\n",c[i], sum);
}

void total_servicios(
	float t[CANTCAT][CANTSEC],
	char s[CANTSEC][LENGTH]
	)
{
	int j = 3
	float sum = 0;

	for (int i = 0; i < CANTCAT; ++i)
	{
		sum += t[i][j];
	}

	printf("total financiado de %s: %.2f\n",s[j], sum);
}

int main()
{
	char categorias[CANTCAT][LENGTH] = {{"micro"}, {"pequeña"}, {"mediana"}};
	char sectores[CANTSEC][LENGTH] = {{"agropecuario"}, {"industria y mineria"}, {"comerico"}, {"servicios"}, {"construccion"}};
	float tabla[CANTCAT][CANTSEC];

	printf("-----CARGA-----\n");
	carga(tabla, categorias, sectores);
	printf("-----TOTAL CATEGORIA-----\n");
	total_categoria(tabla, categorias);
	printf("-----TOTAL SERVICIO-----\n");
	total_servicios(tabla, sectores);

}
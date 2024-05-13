#include <stdio.h>
#define MAQUINAS 3
#define MESES 3


void carga(float c[MESES][MAQUINAS], int i, int j)
{
	if (i<MESES)
	{
		if (j<MAQUINAS)
		{
			printf("combustible: ");
			fflush(stdin);
			scanf("%f", &c[i][j]);
			carga(c,i, j+1);
		} else {
			carga(c, i + 1, 0);
		}
	}
}

void total_fila(float c[MAQUINAS], int i, float sum)
{

	if(i<MAQUINAS)
	{
		sum += c[i];
		total_fila(c, i+1, sum);
	}else printf("total mes 3: %.2f\n",sum);
}

void promedio_por_maquina(float c[MESES][MAQUINAS], int i, int j, float sum)
{
	if (j<MAQUINAS)
	{
		if (i<MESES)
		{
			sum += c[i][j];
			promedio_por_maquina(c,i + 1, j, sum);
		} else {
			printf("promedio maquina %d: %.2f\n",j,sum / MESES);
			promedio_por_maquina(c, 0, j + 1, 0);
		}
	}
}

void maximo_por_maquina(float c[MESES][MAQUINAS], int i, int j, float max, int auxi)
{
	if (j<MAQUINAS)
	{
		if (i<MESES)
		{
			if(c[i][j] > max)
			{
				max = c[i][j];
				auxi = i;
			}
			maximo_por_maquina(c,i + 1, j, max, auxi);
		} else {
			printf("mayor mes maquina %d: %d\n",j,auxi + 1);
			maximo_por_maquina(c, 0, j + 1, 0, 0);
		}
	}
}

int main()
{
	float combustible[MESES][MAQUINAS];
	//float combustible[MESES][MAQUINAS] = {
		//{3.0,4.0,5.0},
		//{2.0,8.0,1.0},
		//{6.0,2.0,9.0},
	//};
	int i = 0, j = 0;
	printf("Holiiss\n");

	printf("-----CARGA-----\n");
	carga(combustible, i, j);
	printf("-----TOTAL FILA-----\n");
	total_fila(combustible[2], i, 0);
	printf("-----PROMEDIO POR MAQUINA-----\n");
	promedio_por_maquina(combustible, i, j, 0);
	printf("-----PROMEDIO POR MAQUINA-----\n");
	maximo_por_maquina(combustible, i, j, 0, 0);
	return 0;
}
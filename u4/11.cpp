#include <stdio.h>
#define N 2

void carga(int x[N][N], int i, int j)
{
	if(i<N)
	{
		if (j<N)
		{
			printf("numero[%d][%d]: ", i, j);
			scanf("%d", &[i][j]);
			carga(x,i,j+1);
		} else carga(x, i+1,0);
	}
}


void producto_escalar_fila(int a[],b[],int j, int sum);
{
	if(j<N)
	{
		sum += a[j] * b[j];
		producto_escalar(a,b,j+1,sum);
	}

	printf("producto escalar: %d\n", sum);
}

void producto_escalar_col(int a[N][N],b[N][N],int i, int c1, int c2, int sum);
{
	if(i<N)
	{
		sum += a[i][c1] * b[i][c2];
		producto_escalar(a,b,i+1,c1,c2,sum);
	}

	printf("producto escalar: %d\n", sum);
}

int main()
{
	//int a[N][N], b[N][N];
	int a[N][N] = {
		{4,5},
		{3,6}
	};
	int b[N][N] ={
		{2,1},
		{7,4}
	};
	int i = 0, j = 0;
	int fila1, fila2, col1,col2;
	//printf("-----CARGA 1-----\n");
	//carga(a,i,j);
	//printf("-----CARGA 2-----\n");
	//carga(b,i,j);
	printf("-----PRODUCTO ESCALAR FILA-----\n");
	printf("ingrese fila 1: ");
	fflush(stdin);
	scanf("%d", &fila1);
	printf("ingrese fila 2: ");
	fflush(stdin);
	scanf("%d", &fila2);
	producto_escalar_fila(a[fila1],b[fila2],j, 0);
	printf("-----PRODUCTO ESCALAR FILA-----\n");
	printf("ingrese columna 1: ");
	fflush(stdin);
	scanf("%d", &col1);
	printf("ingrese columna 2: ");
	fflush(stdin);
	scanf("%d", &col2);
	producto_escalar_col(a,b,j,col1,col2,0);
	return 0;
}
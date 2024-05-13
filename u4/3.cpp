#include <stdio.h>
#define N 3
#define M 3

void carga(int a[N][M], int i, int j)
{
  if(j < M)
  {
    if(i < N)
    {
      printf("numero[%d][%d]: ",i, j);
      scanf("%d", &a[i][j]);
      carga(a,i + 1,j);
    } else carga(a,0,j + 1);
  } else return;
}

void mostrar(int a[N][M], int i, int j)
{
  if(i < N)
  {
    if(j < M)
    {
      printf("%d, ",a[i][j]);
      mostrar(a,i,j+1);
    } else
    {
      printf("\n");
      mostrar(a,i+1,0);
    }
  }
}

void mostrar_reales(int a[N][M], int i, int j)
{
  if(i < N)
  {
    if(j < M)
    {
      printf("%.2f, ",(float)a[i][j]);
      mostrar_reales(a,i,j+1);
    } else
    {
      printf("\n");
      mostrar_reales(a,i+1,0);
    }
  }
}

int main()
{
  int arreglo[N][M];
  int i=0,j=0;
  printf("-----CARGA-----\n");
  carga(arreglo, i, j);
  printf("-----MOSTRAR-----\n");
  mostrar(arreglo, i, j);
  printf("-----MOSTRAR REALES-----\n");
  mostrar_reales(arreglo, i, j);
  return 0;
}

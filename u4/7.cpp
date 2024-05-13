#include <stdio.h>
#define N 3

void inicializar(int a[N], int i)
{
  if (i < N)
  {
    a[i] = 0;
    inicializar(a, i + 1);
  }
}

void carga(int a[N], int i)
{
  if (i < N)
  {
    printf("ingrese un numero: ");
    scanf("%d", &a[i]);
    carga(a, i + 1);
  }
}

void maximo(int a[N],int i, int max)
{
  if(i < N)
  {
    if (a[i] > max) {
    
      max = a[i];
    }
    maximo(a, i, max);
    if(a[i] == max)
    {
      printf("%d es igual al valor maximo\n", i);
    }
  }
}

int main()
{
  int arreglo[N];
  int max=0;
  int i = 0;

  inicializar(arreglo, i);
  printf("-----CARGA-----\n");
  carga(arreglo, i);
  printf("-----maximo-----\n");
  maximo(arreglo, i, max);
  return 0;
}

#include <stdio.h>
#define N 5

void carga(int a[], int i)
{
  if (i < N)
  {
    printf("numero: ");
    scanf("%d", &a[i]);
    carga(a,i + 1);
  }
}

void mostrar(int a[], int i)
{
  if (i < N)
  {
    printf("%d, ", a[i]);
    mostrar(a,i + 1);
  }
}

void mostrar_invertido(int a[], int i)
{
  if (i > 0)
  {
    printf("%d, ", a[i - 1]);
    mostrar_invertido(a,i - 1);
  }
}

void positivos_negativos(int a[], int i, int *p, int *n)
{
  if (i < N)
  {
    if (a[i] >= 0) *p+=1;
    else *n+=1;
    positivos_negativos(a,i+1,p,n);
  } 
}

int main()
{
  int arreglo[N], i = 0;
  int positivos, negativos;
  printf("-----CARGA-----\n");
  carga(arreglo, i);
  printf("-----MOSTRAR-----\n");
  mostrar(arreglo, i);
  printf("\n-----MOSTRAR INVERTIDO-----\n");
  mostrar_invertido(arreglo, N);
  printf("\n-----POSITIVOS NEGATIVOS-----\n");
  positivos_negativos(arreglo,i, &positivos, &negativos);
  printf("positivos: %d\n",positivos);
  printf("negativos: %d\n",negativos);
}

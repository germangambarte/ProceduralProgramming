#include <stdio.h>
#define N 3

void inicializar(int a[N], int i)
{
  if(i < N)
  {
    a[i] = 0;
    inicializar(a, i + 1);
  }
  return;
}

void carga(int a[N], int i)
{
  if(i < N)
  {
    printf("ingrese un entero\n");
    scanf("%d", &a[i]);
    carga(a, i + 1);
  }
  return;
}

void carga_subarreglo(int a[N], int xa[N], int i, int sum, int cont, float prom)
{
  if(prom)
  {

  }
  if(i < N)
  {
    sum += a[i];
    cont += 1;
    carga_subarreglo(a, xa, i+1, sum, cont, prom);
  } else prom =(float) sum / cont;


}

void mayor_igual_promedio(int xa[N], int i, int cont)
{
  if(i < N)
  {
    if(xa[i]!=0)
    {
      cont += 1;
    }
    mayor_igual_promedio(xa, i+1, cont);
  }
  printf("Componentes >= al promedio: %d\n", cont);
  return;
}

void buscar(int a[N], int i, int numero)
{
  if(i < N)
  {

    if(a[N] == numero)
    {
      printf("El numero se encuentra en el arreglo.\n");
      return;
    } else buscar(a, i + 1, numero);

  } else {
    printf("El numero no se encuentra en el arreglo.\n");
    return;
  }
}

int main()
{
  int arreglo[N],xarreglo[N];
  int numero;
  float promedio;
  return 0;
}

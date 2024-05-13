#include <stdio.h>
#define N 4

void carga(float a[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("numero: ");
      scanf("%f", &a[i][j]);
    }
  }
}

float suma_primera_col(float a[N][N])
{
  float sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += a[i][0];
  }
  return sum;
}

float suma_cuarta_fila(float a[N])
{
  float sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += a[i];
  }
  return sum;
}

int calc_cantidad_menor(float a[N][N])
{
  int cont = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (a[i][j] < 25) {
        cont += 1;
      }
    }
  }
  return cont;
}

int calc_cantidad_mayor(float a[N][N])
{
  int i = 0, cont = 0;
  for (int j = 0; j < N; j++)
  {
    if (a[i][j] > 0) {
      cont += 1;
    }
    i++;
  }
  return cont;
}

int main()
{
  float arreglo[N][N];
  float primera_col, cuarta_fila;
  int cantidad_menor, cantidad_mayor;

  carga(arreglo);

  printf("-------------\n");

  primera_col = suma_primera_col(arreglo);
  printf("suma primera columna: %.2f\n",primera_col);

  cuarta_fila = suma_cuarta_fila(arreglo[3]);
  printf("suma cuarta fila: %.2f\n",cuarta_fila);

  cantidad_menor = calc_cantidad_menor(arreglo);
  printf("cantidad de elementos menores a 25: %d\n",cantidad_menor);

  cantidad_mayor = calc_cantidad_mayor(arreglo);
  printf("cantidad de elementos(diagonal) mayores a 0: %d\n",cantidad_mayor);

  return 0;
}
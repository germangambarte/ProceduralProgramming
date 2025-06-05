#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void load(int a[])
{
  srand(time(NULL));
  for (int i = 0; i < N; i++)
  {
    a[i] = rand() % 100;
  }
}

void showEvenPosition(int a[])
{
  for (int i = 0; i < N; i++)
    if (i % 2 == 0)
      printf("%d, ", a[i]);
}

void countEvens(int a[])
{
  int count = 0;
  for (int i = 0; i < N; i++)
    if (a[i] % 2 == 0)
      count++;

  printf("Cantidad de números pares: %d", count);
}

void show(int a[])
{
  for (int i = 0; i < N; i++)
    printf("%d, ", a[i]);
}

int checkZeros(int a[])
{
  int i = 0;
  while (i < N && a[i] != 0)
    i++;
  if (i < N)
  {
    printf("Hay al menos un cero en el array.");
  }
  else
  {
    printf("No hay ceros en el array.");
  }
}

int main()
{
  int arr[N];
  load(arr);
  printf("\n");
  show(arr);
  printf("\n");
  checkZeros(arr);
  printf("\n");
  showEvenPosition(arr);
  printf("\n");
  countEvens(arr);
  printf("\n");
  return 0;
}
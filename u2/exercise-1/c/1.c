#include <stdio.h>
#define N 5

void load(int n[N]) {
  for (int i = 0; i < N; i++) {
    printf("Ingresa el numero que desea cargar:\n");
    scanf("%d", &n[i]);
  }
}

void pairs(int n[N]) {
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (n[i] % 2 == 0)
    {
      printf("%d: %d\n", i+1, n[i]);
      count = count  + 1;
    }
  }
  printf("El arreglo contiene %d numeros pares\n", count);
}

int main () {
  int numbers[N];
  load(numbers);
  pairs(numbers);
  return 0;
} 

#include <stdio.h>
#include <stdlib.h>
#define ROWS 3 
#define COLS 4 

void carga(int a[ROWS][COLS]){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
        a[i][j] = rand() % ROWS * 9;
    }
  }
}

void imprimir(int a[ROWS][COLS]){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
        printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
}

int sumador(int a[ROWS][COLS]){
  int sum = 0;
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      if(a[i][j] % 2 == 1) sum += 1;
    }
  }
  return sum;
}

int contador_por_fila(int a[ROWS][COLS], int row){
  int cont = 0;
  for(int i = 0; i < ROWS; i++){
    if(i == row - 1) {
      for(int j = 0; j < COLS; j++){
        if(a[i][j] > 10) cont += 1;
      }
    }
  }
  return cont;
}

int main(){
  int arr[ROWS][COLS], sum, cont;
  carga(arr);
  imprimir(arr);
  printf("---------\n");

  sum = sumador(arr);
  printf("suma de impares: %d\n", sum);
  printf("---------\n");

  cont = contador_por_fila(arr, 2);
  printf("hay %d mayores que %d\n", cont, 10);
  printf("---------\n");

  return 0;
  }


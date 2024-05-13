#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLUMNS 4

void carga(int t[ROWS][COLUMNS]){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLUMNS; j++){
      t[i][j] = rand() % ROWS * 3;
    }
  }
}

void imprimir_tabla(int t[ROWS][COLUMNS]){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLUMNS; j++){
      printf("%d ", t[i][j]);
    }
    printf("\n");
  }
}
void suma(int t[ROWS][COLUMNS]){
  int sum = 0;
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLUMNS; j++){
      sum += t[i][j];
    }
    printf("total fila %d: %d\n", i, sum);
    sum = 0;
  }
}

void promedio_por_columna(int t[ROWS][COLUMNS], int col){
  int sum = 0, contador = 0;
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLUMNS; j++){
      if(j == col - 1){
        sum += t[i][j];
        contador += 1;
      }
    }
  }
  printf("promedio columna %d: %d\n", col, sum / contador);
}

void hallar_mayores(int t [ROWS][COLUMNS], int num){
  int contador = 0;
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLUMNS; j++){
      if(t[i][j] > num){
        contador += 1;
      }
    }
  }
  printf("Hay %d numeros mayores que %d", contador, num);
}


int main(){
  int tabla[ROWS][COLUMNS];
  carga(tabla);
  imprimir_tabla(tabla);
  printf("----------------------\n");
  suma(tabla);
  printf("----------------------\n");
  promedio_por_columna(tabla, 3);
  printf("----------------------\n");
  hallar_mayores(tabla, 10);
}

#include <stdio.h>
#include <stdlib.h>
#define ROWS 4 
#define COLS 6

void inicializar(int c[ROWS][COLS]){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
        c[i][j] = 0;
    }
  }
}

void carga(int a[ROWS][COLS]){
  int sala, turno;

  printf("Ingrese la sala(termina con 0): ");
  scanf("%d", &sala);

  while(sala != 0){
    printf("Ingrese el turno: ");
    scanf("%d", &turno);

    a[turno - 1][sala - 1] += 1;
    turno = 0;
    sala = 0;

    printf("Ingrese la sala(termina con 0): ");
    scanf("%d", &sala);
  }
}

void imprimir(int c[ROWS][COLS]){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
        printf("%d\t", c[i][j]);
    }
    printf("\n");
  }
}

void imprimir_detalle(int c[ROWS][COLS]){
  for(int i = 0; i < ROWS; i++){
    printf("turno: %d\n", i + 1);
    for(int j = 0; j < COLS; j++){
        printf("area %d: %d inscriptos\n", j+1, c[i][j]);
    }
  }
}

void promedio_por_tematica(int c[ROWS][COLS], int area){
  int sum = 0, cont = 0;
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      if(j == area - 1){
        sum += c[i][j];
        cont += 1;
      }
    }
  }
  printf("promedio inscriptos tematica %d: %d", area, sum / cont);
}

int main(){
  int conferencias[ROWS][COLS];
  inicializar(conferencias);
  carga(conferencias);
  imprimir(conferencias);
  printf("---------\n");
  imprimir_detalle(conferencias);
  printf("---------\n");
  promedio_por_tematica(conferencias, 3);

  return 0;
  }


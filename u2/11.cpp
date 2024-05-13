#include <stdio.h>
#define ROWS 8
#define COLS 12

void inicializar(int imp[ROWS][COLS]){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
        imp[i][j] = 0;
    }
  }
}

void carga(int imp[ROWS][COLS]){
  int mes, departamento;
  float importe;

  printf("mes(termina con 0): ");
  scanf("%d", &mes);

  while(mes != 0){
    printf("departamento: ");
    scanf("%d", &departamento);
    printf("importe: ");
    scanf("%d", &importe);

    imp[departamento-1][mes-1] += importe;
    mes = 0;
    departamento = 0;
    importe = 0;

    printf("mes(termina con 0): ");
    scanf("%d", &mes);
  }
}

void imprimir(int imp[ROWS][COLS]){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
        printf("%d\t", imp[i][j]);
    }
    printf("\n");
  }
}

int minimo(int imp[ROWS][COLS]){
  int min = 9999999, depto,mes;
  
  printf("mes: ");
  scanf("%d", &mes);
  for(int i = 0; i < ROWS; i++){
      if(imp[i][mes - 1] < min){
        min = imp[i][mes - 1];
        depto = i;
    }
  }
  return depto + 1;
}

float promedio(int imp[ROWS][COLS]){
  int sum = 0, cont = 0;
  float prom = 0;
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      sum += imp[i][j];
      cont += 1;
    }
  }
  prom = sum / cont;
  printf("promedio: %.2f", prom);
  return prom;
}

void chequear_promedio(int imp[ROWS][COLS], float prom){
  int mes, depto;

  printf("mes: ");
  scanf("%d", &mes);
  printf("departamento: ");
  scanf("%d", &depto);

  if(imp[depto][mes] > prom) {
    printf("El importe es superior al promedio\n");
  } else {
    printf("El importe no es superior al promedio\n");
  }
}

int main(){
  int importes[ROWS][COLS], min;
  float prom;

  inicializar(importes);
  printf("\n-----CARGA-----\n");
  carga(importes);
  printf("\n-----DETALLE-----\n");
  min = minimo(importes);
  printf("departamento con menos ventas: %d\n", min);
  printf("\n-----PROMEDIO-----\n");
  prom = promedio(importes);
  printf("\n-----COMPARAR-----\n");
  chequear_promedio(importes, prom);

  return 0;
  }


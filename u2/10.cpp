#include <stdio.h>
#define ROWS 2
#define COLS 45

void inicializar(int f[ROWS][COLS]){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
        f[i][j] = 0;
    }
  }
}

void carga(int f[ROWS][COLS]){
  int codigo, cantidad;

  for (int i = 0; i < ROWS; i++) {
    printf("-----farmacia: %d-----\n",i + 1);
    printf("codigo(termina con 0): ");
    scanf("%d", &codigo);
    while(codigo != 0){
      printf("cantidad: ");
      scanf("%d", &cantidad);

      f[i][codigo - 100] += cantidad;
      codigo = 0;
      cantidad = 0;

      printf("codigo(termina con 0): ");
      scanf("%d", &codigo);
    }
  }
}

void imprimir(int f[ROWS][COLS]){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
        printf("%d\t", f[i][j]);
    }
    printf("\n");
  }
}

void imprimir_detalle(int f[ROWS][COLS]){
  int sum = 0;
  for(int j = 0; j < COLS; j++){
    for(int i = 0; i < ROWS; i++){
      sum += f[i][j];
    }
    printf("del medicamento %d se vendio: %d unidades\n", j+100, sum);
    sum = 0;
  }
}

void maximo(int f[ROWS][COLS]){
  int max = 0, cod_far, med;

  printf("codigo de farmacia: ");
  scanf("%d", &cod_far);

  for(int j = 0; j < COLS; j++){
    if(f[cod_far - 1][j] > max){
      max = f[cod_far - 1][j];
      med = j,
    }
  }

  printf("mas vendido: %d medicamentos(cod: %d)\n", max, med + 100);
}

int main(){
  int farmacias[ROWS][COLS];

  inicializar(farmacias);
  printf("\n-----CARGA-----\n");
  carga(farmacias);
  printf("\n-----DETALLE-----\n");
  imprimir_detalle(farmacias);
  printf("\n-----MAXIMO-----\n");
  maximo(farmacias);

  return 0;
  }


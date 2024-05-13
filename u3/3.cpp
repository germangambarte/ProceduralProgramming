/* 
  * Un laboratorio abastece a 30 farmacias de la provincia. 
  * Dicho laboratorio comercializa 80 medicamentos (1..80) de los que se debe registrar: 

  * Código de medicamento
  * nombre
  * precio unitario.

  * Se ingresan las ventas realizadas ordenada por farmacia.

  * Por cada venta a una farmacia se ingresa: 

  * código de medicamento
  * cantidad de unidades, finalizando con código de medicamento igual a 0 (cero)

  Codificar un programa en C, que utilizando funciones permita:

  1. Calcular y mostrar total de unidades vendidas de cada uno de los medicamentos.
  2. Escribir el/los códigos/s del/los medicamento/s por el que se recaudó mayor importe.
  3. Indicar la cantidad de unidades vendidas para un código de medicamento ingresado por teclado.
  4. Dado el nombre de un medicamento indicar el importe total recaudado y la cantidad de 
  unidades vendidas.
  5. Indicar la cantidad de unidades vendida a cada farmacia y el importe total que pagó cada una.
* */

#include <stdio.h>
#include <string.h>
#define CADENA 20
#define CANTFARMACIAS 3
#define CANTMEDICAMENTOS 3

typedef struct {
  int codigo;
  char nombre[CADENA];
  float precio_unitario;
  int cantidad_vendidas;
} medicamento;

void carga(medicamento m[CANTFARMACIAS][CANTMEDICAMENTOS]){
  for (int i = 0; i < CANTFARMACIAS; i++){
    for (int j = 0; j < CANTMEDICAMENTOS; j++){
      printf("nombre: ");
      gets(m[i][j].nombre);
      printf("codigo: ");
      scanf("%d", &m[i][j].codigo);
      printf("precio: ");
      scanf("%d", &m[i][j].precio_unitario);
    }
  }
}

void procesar(medicamento m[CANTFARMACIAS][CANTMEDICAMENTOS]){
  int codigo, cantidad;
  for (int i = 0; i < CANTFARMACIAS; i++){
    printf("-----Farmacia %d-----", i + 1);
    printf("codigo: ");
    scanf("%d", &codigo);
    while(codigo != 0){
      printf("cantidad: ");
      scanf("%d", &cantidad);

      m[i][codigo - 1].cantidad_vendidas += cantidad;

      codigo = 0;

      printf("codigo: ");
      scanf("%d", &codigo);
    }
  }
}

void unidades_vendidas(medicamento m[CANTFARMACIAS][CANTMEDICAMENTOS]){
  int sum = 0;
  for (int j = 0; j < CANTMEDICAMENTOS; j++){
    for (int i = 0; i < CANTFARMACIAS; i++){
      sum += m[i][j].cantidad_vendidas;
    }
    printf("unidades vendidas del medicamento %d: %d", j + 1, sum);
    sum = 0;
  }
}

void mayor_recaudador(medicamento m[CANTFARMACIAS][CANTMEDICAMENTOS]){
  float importes[CANTMEDICAMENTOS];
  float max = 0, total;
  for (int j = 0; j < CANTMEDICAMENTOS; j++){
    for (int i = 0; i < CANTFARMACIAS; i++){
      total = m[i][j].cantidad_vendidas * m[i][j].precio_unitario;
      importes[j] += total;
    }
    if (importes[j] > max) max = importes[j];
  }
  printf("mayor recaudacion: ");
  for (int i = 0; i < CANTMEDICAMENTOS; i++){
    if (importes[i] == max) printf("%d, ", i + 1);
  }
  printf("\n");
}

void mostrar_unidades_por_busqueda(medicamento m[CANTFARMACIAS][CANTMEDICAMENTOS]){
  float sum = 0, total;
  int codigo;

  printf("codigo: ");
  scanf("%d", &codigo);

  for (int i = 0; i < CANTFARMACIAS; i++){
      sum = m[i][codigo - 1].cantidad_vendidas;
  }
}


int main(){
  medicamento medicamentos[CANTFARMACIAS][CANTMEDICAMENTOS];
  int stock_nulo, precio_mayor;

  printf("-----CARGA MEDICAMENTOS-----\n");
  carga(medicamentos);
  printf("-----PROCESAR-----\n");
  procesar(medicamentos);
  printf("-----UNIDADES VENDIDAS-----\n");
  unidades_vendidas(medicamentos);
  printf("-----MAYOR RECAUDADOR-----\n");
  mayor_recaudador(medicamentos);
  printf("-----TOTAL POR ARTICULOS-----\n");
  total_por_articulo(articulos);

  return 0;
}

/* Un local comercial de ventas de repuestos de automotores desea obtener cierta información
 * sobre todas las ventas registradas en un periodo de tiempo dado.
 
 * El comercio cuenta con 250 artículos, almacenados en una estructura y de los cuales se 
 conocen los siguientes datos: 
 * Código
 * Nombre
 * Precio Unitario
 * Stock
 
 * Se procesan las ventas y los datos ingresados de cada una son: 
 * Nombre del artículo
 * Cantidad de unidades vendidas (con esta información actualizar el stock de cada artículo).
 
 * El ingreso de ventas termina con nombre igual “FIN”.
 
 * Se pide realizar un programa en C, que utilizando subprogramas óptimos y estructuras adecuadas permita:
  1. Procesar las ventas registradas en ese periodo de tiempo.
  2. Mostrar en el main la cantidad de artículos que quedaron con stock nulo y cuantos
  tienen un precio mayor a $7000.
  3. Imprimir los nombres de los 20 artículos que quedaron con mayor stock.
  4. Indicar para cada artículo el monto total obtenido por ventas.
* */

#include <stdio.h>
#include <string.h>
#define CADENA 20
#define CANTARTICULOS 3

typedef struct {
  char nombre[CADENA];
  int codigo;
  float precio_unitario;
  int stock;
  float total_ventas;
} articulo;

void carga_articulos(articulo a[CANTARTICULOS]){
  for (int i = 0; i < CANTARTICULOS; i++) {
    printf("codigo: ");
    scanf("%d", &a[i].codigo);
    printf("nombre: ");
    fflush(stdin);
    gets(a[i].nombre);
    printf("precio: ");
    scanf("%f", &a[i].precio_unitario);
    printf("stock: ");
    scanf("%d", &a[i].stock);
    a[i].total_ventas = 0;
    printf("----------\n");
  }
}

void procesar_ventas(articulo a[CANTARTICULOS]){
  char nombre[CADENA];
  int stock;

  printf("nombre: ");
  fflush(stdin);
  gets(nombre);

  while(stricmp(nombre, "FIN") != 0){
    printf("stock: ");
    scanf("%d", &stock);

    for (int i = 0; i < CANTARTICULOS; i++) {
      if(stricmp(a[i].nombre,nombre) == 0){
        a[i].total_ventas += stock * a[i].precio_unitario;
        a[i].stock -= stock;
      }
    }

    stock = 0;

    printf("nombre: ");
    fflush(stdin);
    gets(nombre);
  }
}

int buscar(articulo a[CANTARTICULOS], int &precio_mayor){
  int stock_nulo = 0;
  for (int i = 0; i < CANTARTICULOS; i++) {
    if (a[i].stock == 0) stock_nulo += 1;
    if (a[i].precio_unitario > 7000) precio_mayor += 1;
  }
  return stock_nulo;
}

void ordenar(articulo a[CANTARTICULOS]){
  int k = 1, cota = CANTARTICULOS;
  articulo aux;
  while (k != -1){
    k = -1;
    for (int i = 0; i < cota; i++){
      if (a[i].stock < a[i+1].stock){
        aux = a[i];
        a[i] = a[i+1];
        a[i+1] = aux;
        k = i;
      }
    }
    cota = k;
  }
}

void mostrar_ultimos(articulo a[CANTARTICULOS]){
  printf("{\n");
  for (int i = CANTARTICULOS - 2; i < CANTARTICULOS; i++) {
    printf("%s,\n", a[i].nombre);
  }
  printf("}\n");
}

void total_por_articulo(articulo a[CANTARTICULOS]){
  printf("{\n");
  for (int i = 0; i < CANTARTICULOS; i++) {
    printf("\tarticulo: %s,\n", a[i].nombre);
    printf("\tventas totales: %.2f,\n", a[i].total_ventas);
  }
  printf("}\n");
}

int main(){
  articulo articulos[CANTARTICULOS];
  int stock_nulo, precio_mayor;

  printf("-----CARGA-----\n");
  carga_articulos(articulos);
  printf("-----PROCESAR-----\n");
  procesar_ventas(articulos);
  printf("-----STOCK NULO-----\n");
  stock_nulo = buscar(articulos, precio_mayor);
  printf("-----ULTIMOS 20-----\n");
  mostrar_ultimos(articulos);
  printf("-----TOTAL POR ARTICULOS-----\n");
  total_por_articulo(articulos);

  return 0;
}

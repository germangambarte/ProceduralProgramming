#include<stdio.h>
#define CANTPRODS 100

typedef struct
{
  int codigo;
  float precio_unitario;
  int cantidad_vendidas;
} producto;

void carga(producto p[CANTPRODS])
{
  for (int i = 0; i < CANTPRODS; ++i)
  {
    printf("codigo: ");
    scanf("%d", &p[i].codigo);
    printf("precio unitario: ");
    scanf("%f", &p[i].precio_unitario);
    p[i].cantidad_vendidas = 0;
  }
}

void procesar(producto p[CANTPRODS])
{
  int codigo, cantidad;
  printf("codigo: ");
  scanf("%d", &codigo);

  while(codigo != 0)
  {
    printf("cantidad: ");
    scanf("%d", &cantidad);

    p[codigo - 100].cantidad_vendidas += cantidad;

    codigo = 0;

    printf("codigo: ");
    scanf("%d", &codigo);

  }
}

void mostrar_cantidades(producto p[CANTPRODS])
{
  for (int i = 0; i < CANTPRODS; ++i)
  {
    printf("el producto %d vendio %d unidades\n", i + 100, p[i].cantidad_vendidas);
  }
}

float mayor_recaudacion(producto p[CANTPRODS], producto &max_recaudador)
{
  float max_importe = 0, importe_producto;
  for (int i = 0; i < CANTPRODS; ++i)
  {
    importe_producto = p[i].cantidad_vendidas * p[i].precio_unitario;
    if(importe_producto > max_importe)
    {
      max_importe = importe_producto;
      max_recaudador = p[i];
    }
  }
  return max_importe;
}

void cantidad_respecto_total(producto p[CANTPRODS])
{
  for (int i = 20; i < 50; ++i)
  {
    /* code */
  }
}

int main(){
  producto productos[CANTPRODS];
  int unidades_por_producto[CANTPRODS];
  producto max_recaudador;
  max_importe;

  printf("-----CARGA-----\n");
  carga(productos);
  printf("-----PROCESAR-----\n");
  procesar(productos, unidades_por_producto);
  printf("-----CANTIDADES POR PRODUCTO-----\n");
  mostrar_cantidades(productos);
  printf("-----MAX RECAUDACION-----\n");
  max_importe = mayor_recaudacion(productos, max_recaudador);
  printf("codigo %d,\n", max_recaudador.codigo);
  printf("cantidad vendidas: %d,\n", max_recaudador.cantidad_vendidas);
  printf("importe total %d,\n", max_importe);

  return 0;
}

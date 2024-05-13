#include <stdio.h>
#define CANTLENG 6

void inicializar(int l[CANTLENG], int i)
{
  if(i < CANTLENG)
  {
    l[i] = 0;
    inicializar(l, i + 1);
  }
}

void carga(int l[CANTLENG], int i)
{
  int cod;
  printf("elija un curso (0 para terminar): ");
  scanf("%d", &cod);
  if(cod)
  {
    l[cod - 1] += 1;
    carga(l,i);
  }
  return;
}

void mostrar_menos_4000(int l[CANTLENG], int i)
{
  if(i < CANTLENG)
  {
    if(l[i] < 4000)
    {
      printf("lenguaje nro %d tiene menos de 4000 encuestados.\n", i + 1);
    }
    mostrar_menos_4000(l, i + 1);
  }
  return;
}
void maximo(int l[CANTLENG], int i, int max, int xi)
{
  if(i < CANTLENG)
  {
    if(l[i] > max)
    {
      max = l[i];
      xi = i;
    }
    maximo(l, i+1, max, xi);
  }
  printf("Lenguaje mas elegido: %d\n", xi);
}

void contador(int l[CANTLENG], int i, int cont)
{
  if(i < 0)
  {
    cont += l[i];
    contador(l, i+1, cont);
  }
  printf("Cantidad de encuestados: %d\n", cont);
}

void mostrar_h()

int main()
{
  int lenguajes[CANTLENG];
  int prueba[] = {4567,2345,7543,1234,3456};
  int i = 0;

  inicializar(lenguajes, i);
  printf("----CARGA----\n");
  carga(lenguajes, i);
  return 0;
}

#include <stdio.h>
#include <malloc.h>

typedef struct {
  int dni;
  int plan;
  float monto;
} adj;

void crear(adj *&a, int N) {
  a = (adj*)malloc(sizeof(adj)* N);
}

void carga(adj *a, int N){
  for (int i = 0; i < N; i++) {
    printf("dni: \n");
    scanf("%d", &a->dni);
    printf("plan: \n");
    scanf("%d", &a->plan);
    printf("monto: \n");
    scanf("%d", &a->monto);
  }
}

void buscar_por_dni(adj *a, int N){
  int dni;
  printf("ingrese el dni: ");
  scanf("%d", &dni);
  for (int i = 0; i < N; i++)
  {
    if(a[i].dni == dni){
      printf("plan: %d, monto adeudado: %.2f\n",a[i].plan,a[i].monto);
    }
    return;
  }
}

void adjudicatarios_por_plan(adj *a, int N){
  int cont = 0, planes = 5;
  for (int i = 0; i < planes; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if(a[j].plan == i + 1) cont += 1;
    }
    printf("adjudicatarios del plan %d: %d", i+1,cont);
    cont = 0;
  }
}


int main()
{
  adj *adjs;
  int cantidad, indice;
  printf("cantidad: \n");
  scanf("%d", &cantidad);
  crear(adjs,cantidad);
  carga(adjs,cantidad);
}

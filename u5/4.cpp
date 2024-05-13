#include<stdio.h>
#include<malloc.h>
#define CARACTERES 255

typedef struct {
  int plan;
  int dni;
  char nya[];
  int cuotas_pagadas;
}adj;

void carga(adj *a, int N){
  for (int i = 0; i < N; i++)
  {
    printf("nombre y apellido: ");
    gets(a[i].nya);
    printf("dni: ");
    scanf("%d", &a[i].dni);
    printf("plan: ");
    scanf("%d", &a[i].plan);
    printf("cuotas pagadas: ");
    scanf("%d", &a[i].cuotas_pagadas);
  }
}

void generar_estructura(adj *a, adj *&xa, int N){
  int xN = 0, aux_i = 0;
  for (int i = 0; i < N; i++)
  {
    if(a[i].cuotas_pagadas > 30) xN +=1;
  }
  xa = (adj *) malloc(sizeof(adj) * xN);
  for (int j = 0; j < N; j++)
  {
    if(a[j].cuotas_pagadas > 30) {
      xa[aux_i] = a[j];
    }
  }
}

int main(){
  adj *adjs, *adjs_aptos;
  int cantidad;
  printf("cantidad de adjudicatarios: ");
  scanf("%d", &cantidad);
  adjs = (adj *) malloc(sizeof(adj) * cantidad);
  carga(adjs, cantidad);
  generar_estructura(adjs, adjs_aptos, cantidad);
  return 0;
}
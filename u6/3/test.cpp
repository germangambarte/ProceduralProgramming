#include<stdio.h>
#include<malloc.h>

typedef struct puntero {
  int nro;
  float importe;
  int tipo;
  struct puntero *sig;
} nodo;

void crear(nodo *&c){
  c = NULL;
}

void insercion(nodo *&c){
  int nro;
  nodo *nuevo;
  printf("numero (finaliza con 0): ");
  scanf("%d",&nro);
  while(nro != 0){
    // if(nro > 0){
      nuevo = (nodo *) malloc(sizeof(nodo));
      nuevo->nro = nro;
      printf("importe: ");
      scanf("%f", &nuevo->importe);
      printf("tipo: ");
      scanf("%d", &nuevo->tipo);
      nuevo->sig = c;
      c = nuevo;
    printf("numero (finaliza con 0): ");
    scanf("%d",&nro);
  }
}

void recorre(nodo *c){
  if (c != NULL){
		printf(
			"numero: %i, importe: %.2f, tipo: %d\n",
			c->nro, c->importe ,c->tipo
			);
    recorre(c->sig);
  } else {
    return;
  }
}

int main(){
  nodo *cabeza;
  crear(cabeza);
  printf("-----CARGA-----\n");
  insercion(cabeza);
  printf("-----RECORRE-----\n");
  recorre(cabeza);

  return 0;
}
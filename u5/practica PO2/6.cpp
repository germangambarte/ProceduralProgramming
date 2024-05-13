#include <stdio.h>
#include <malloc.h>

typedef struct _entero {
  int numero;
  _entero *sig;
}Entero;

void crear(Entero *&e){
  e = NULL;
}

void carga(Entero *&e){
  Entero *nuevo, *anterior, *actual;
  nuevo = (Entero*)malloc(sizeof(Entero));
  printf("numero: ");
  scanf("%d", &nuevo->numero);
  while (nuevo->numero != 0)
  {
    nuevo = NULL;
    if(e == NULL){
      e = nuevo;
    } else {
      actual = e;
      while(actual != NULL){
        anterior = actual;
        actual = actual->sig;
      }
      anterior->sig = nuevo;
    }
  printf("numero: ");
  scanf("%d", &nuevo->numero);
  }
}

void ordenar(Entero *e){
  Entero *actual,*bandera, *ultimo;
  int aux;
  ultimo = NULL;
  bandera = NULL;
  while(bandera != e){
    bandera = e;
    actual = e;
    while(actual->sig != ultimo){
      if(actual->numero > actual->sig->numero){
        aux = actual->sig->numero;
        actual->sig->numero = actual->numero;
        actual->numero = aux;
        bandera = actual;
      } else {
        actual = actual->sig;
      }
      ultimo = bandera->sig;
    }
  }
}

void mostrar(Entero *e){
  if(e!=NULL){
    printf("%d, ",e->numero);
    mostrar(e->sig);
  } else {
    return ;
  }
}

int main(){
  Entero *enteros;
  crear(enteros);
  carga(enteros);
  ordenar(enteros);
}
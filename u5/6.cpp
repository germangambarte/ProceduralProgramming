#include<stdio.h>
#include<malloc.h>

typedef struct puntero {
  int nro;
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
    if(nro > 0){
      nuevo = (nodo *) malloc(sizeof(nodo));
      nuevo->nro = nro;
      nuevo->sig = c;
      c = nuevo;
      }
    printf("numero (finaliza con 0): ");
    scanf("%d",&nro);
  }
}

void recorre(nodo *c){
  if (c != NULL){
    printf("%d, ", c->nro);
    recorre(c->sig);
  } else {
    return;
  }
}

void ordenar(nodo *c){
  nodo *k,*cota,*actual;
  int aux;
  cota = NULL;
  k = NULL;

  while(k != c){
    k = c;
    actual = c;
    while(actual->sig != cota){
      if(actual->nro > actual->sig->nro){
      aux = actual->sig->nro;
      actual->sig->nro = actual->nro;
      actual->nro = aux;
      k = actual;
      }
    actual = actual ->sig;
    }
    cota = k->sig;
  }
}

void ultimo_par(nodo *c){
  if(c->sig != NULL){
    ultimo_par(c->sig);
  } else {
    printf("ultimo numero: %d\n",c->nro);
    if(c->nro %2 ==0) {
      printf("El ultimo numero es par\n");
    } else {
      printf("El ultimo numero no es par\n");
    }
    return ;
  }
}

void inverso(nodo *c){
  if(c != NULL){
    inverso(c->sig);
    printf("%d, ", c->nro);
  } 
  return ;
}

void buscar(nodo *c,int nro){
  if(c != NULL && c->nro != nro){
    buscar(c->sig,nro);
  } else {
    if (c==NULL) {
      printf("el numero no está en la lista");
    } else {
      printf("el numero está en la lista");
    }
  }
}

void modificar(nodo *&c){
  int viejo,nuevo;
  printf("numero a cambiar");
  scanf("%d", &viejo);
  printf("nuevo numero: ");
  scanf("%d", &nuevo);
  while (c != NULL && c->nro!=viejo){
    c = c->sig;
  }
  if(c!=NULL){
    c->nro = nuevo;
  } else{
    printf("no se encontro el numero");
  }
}

void eliminar(nodo *c){
  nodo *anterior, *actual;
  int nro;
  printf("ingrese el numero que desea eliminar: ");
  scanf("%d", &nro);
  while (actual != NULL & actual->nro!=nro){
    anterior = actual;
    actual = actual->sig;
  }
  if(actual != NULL){
    anterior->sig = actual->sig;
    free(actual);
    printf("eliminado");
  } else {
    printf("no se encontro el numero");
  }
}

void limpiar(nodo *c){
  nodo *actual;
  if(c != NULL){
    actual = c;
    c = c->sig;
    free(actual);
    limpiar(c);
  } else {
    return;
  }
}


int main(){
  nodo *cabeza;
  crear(cabeza);
  printf("-----CARGA-----\n");
  insercion(cabeza);
  ordenar(cabeza);
  printf("-----RECORRE-----\n");
  recorre(cabeza);
  printf("\n-----PAR-----\n");
  ultimo_par(cabeza);
  printf("-----INVERSO-----\n");
  inverso(cabeza);
  return 0;
}

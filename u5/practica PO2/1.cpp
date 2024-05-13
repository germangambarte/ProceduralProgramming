#include<stdio.h>
#include<malloc.h>

void crear(int *&x, int N){
  x = (int *) malloc(sizeof(int) * N);
}

void carga(int *&x, int N, int i){
  if(i < N){
    printf("numero: ");
    scanf("%d", &x[i]);
    carga(x,N,i + 1);
  } else {
    return ;
  }
}

void mostrar(int *x, int N, int i){
  if(i<N){
    printf("%d, ", x[i]);
    mostrar(x,N,i+1);
  } else {
    printf("\n");
    return ;
  }
}

void productoEscalar(int *xa,int *xb, int N, int i, int sum){
  if(i<N){
    sum +=xa[i] * xb[i];
    productoEscalar(xa,xb,N,i+1,sum);
  }else {
    printf("producto escalar: %d\n", sum);
    return ;
  }
}

int nuevaEsctructura(int *x, int *&p, int N){
  int cont = 0, j = 0;
  for (int i = 0; i < N; i++){
    if(x[i] % 2 == 0){
      cont += 1;
    }
  }
  p = (int *) malloc(sizeof(int)*cont);
  for (int k = 0; k < N; k++){
    if(x[k] % 2 == 0){
      p[j] = x[k];
      j += 1;
    }
  }
  return j;
}

int main(){
  int N, M, *A,*B, *C;
  printf("longitud de los arreglos: ");
  scanf("%d", &N);
  crear(A,N);
  crear(B,N);
  printf("-----CARGA A-----\n");
  carga(A,N,0);
  printf("-----CARGA B-----\n");
  carga(B,N,0);
  printf("-----MOSTRAR-----\n");
  mostrar(A,N,0);
  mostrar(B,N,0);
  printf("-----PRODUCTO ESCALAR-----\n");
  productoEscalar(A,B,N,0,0);
  printf("-----NUEVA ESTRCUTURA-----\n");
  M = nuevaEsctructura(A,C,N);
  mostrar(C,M,0);
  free(A);
  free(B);
  free(C);
}
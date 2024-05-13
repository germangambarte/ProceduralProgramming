#include <stdio.h>
#include <malloc.h>

void carga(int *&x, int N){
  x = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++)
  {
    printf("numero: ");
    scanf("%d", &x[i]);
  }
}

void mostrar(int *x, int N){
  for (int i = 0; i < N; i++)
  {
    printf("%d, ", x[i]);
  }
  printf("\n");
}

void producto_escalar(int *a, int *b, int i, int N, int sum){
  if(i < N){
    sum += a[i] * b[i];
    producto_escalar(a,b,i+1,N,sum);
  } else {
    printf("producto escalar: %d\n", sum);
    return;
  }
}

void subarreglo_dinamico(int *a, int *&x, int N) {
  int *b;
  int aux = 0;
  b = (int*)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++)
  {
    if(a[i] % 2 == 0)
    {
      b[aux] = a[i];
      aux += 1;
    }
  }
  x = (int *)malloc(sizeof(int)*aux);
  for (int i = 0; i < aux; i++)
  {
    x[i] = b[i];
    printf("%d, ", x[i]);
  }
  free(b);
}

int main(){
  int *a,*b, *c;
  int tam, i = 0, suma = 0;
  printf("-----TAMAÑO-----\n");
  printf("tamaño: ");
  scanf("%d", &tam);
  printf("-----CARGA-----\n");
  carga(a, tam);
  carga(b, tam);
  printf("-----MOSTRAR-----\n");
  mostrar(a, tam);
  mostrar(b, tam);
  printf("-----PRODUCTO ESCALAR-----\n");
  producto_escalar(a,b,i,tam,suma);
  printf("-----SUBARREGLO-----\n");
  subarreglo_dinamico(a,c,tam);
  free(a);
  free(b);
  free(c);
  return 0;
}
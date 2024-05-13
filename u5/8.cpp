#include<stdio.h>
#include<malloc.h>
#define N 12

typedef struct nodo {
  int dni;
  int especialidad;
  struct nodo *sig;
} inscripto;

typedef struct {
  int numero;
  char *nombre_especialidad;
  inscripto *inscriptos;
} tutorial;

void crear_nodo_tutorial(tutorial &c){
  c.inscriptos=NULL;
}

void crear(tutorial t[N]){
  for (int i = 0; i < N; i++){
    t[i].numero=1;
    printf("nombre: ");
    gets(t[i].nombre_especialidad);
    crear_nodo_tutorial(t[i]);
  }
}

int main(){
  int i, n, op;
  long d;
  tutorial tutoriales[N];
  crear(tutoriales);

  return 0;
}
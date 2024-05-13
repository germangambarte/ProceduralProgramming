#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct {
  int dni;
  int edad;
  char estado[10];
  char tipo;
} Socio;

void crear(Socio *&s, int N){
  s = (Socio *) malloc(sizeof(Socio)*N);
}

void carga(Socio *&s, int N, int i){
  char tipo;
  if(i < N){
    printf("tipo: ");
    fflush(stdin);
    scanf("%c", &tipo);
    if(tipo == 'A' || tipo == 'J'){
      s[i].tipo = tipo;
      printf("dni: ");
      fflush(stdin);
      scanf("%d", &s[i].dni);
      printf("edad: ");
      fflush(stdin);
      scanf("%d", &s[i].edad);
      printf("estado: ");
      fflush(stdin);
      gets(s[i].estado);
      carga(s,N,i+1);
    } else {
      carga(s,N,i);
    }
  } else {
    return ;
  }
}

void mostrar(Socio *s, int N, int i){
  if(i< N){
    printf(
      "dni: %i, edad: %i, tipo: %c, estado: %s\n",
      s[i].dni,s[i].edad,s[i].tipo,s[i].estado
      );
      mostrar(s,N,i + 1);
  } else {
    return ;
  }
}
void mostrarDNI(Socio *s, int N, int i){
  int cont = 0,m = 0;
  Socio *aux;
  for (int i = 0; i < N; i++){
    if(s[i].tipo =='A' && s[i].edad > 40){
      cont += 1;
    }
  }
  aux = (Socio*) malloc(sizeof(Socio) * cont);
  for (int j = 0; j < N; j++){
    if(s[j].tipo =='A' && s[j].edad > 40){
      aux[m] = s[j];
      m+=1;
    }
  }
  for (int k = 0; k < cont; k++){
    printf("dni: %d\n", aux[k].dni);
  }
  free(aux);
}

void activos(Socio *x, int N, char t){
  int cont = 0,m = 0;
  Socio *aux;
  for (int i = 0; i < N; i++){
    if(strcmp(x[i].estado,"Activo") == 0 && x[i].tipo == t){
      cont += 1;
    }
  }
  aux = (Socio*) malloc(sizeof(Socio) * cont);
  for (int j = 0; j < N; j++){
    if(strcmp(x[j].estado,"Activo")==0 && x[j].tipo == t){
      aux[m] = x[j];
      m+=1;
    }
  }
  for (int k = 0; k < cont; k++){
    printf(
      "dni: %i, edad: %i, tipo: %c, estado: %s\n",
      aux[k].dni,aux[k].edad,aux[k].tipo,aux[k].estado
      );
  }
  free(aux);
}

int main(){
  Socio *socios;
  int N;
  printf("cantidad de socios: ") ;
  scanf("%d", &N);
  crear(socios,N);
  printf("-----CARGAR-----\n");
  carga(socios,N,0);
  printf("-----MOSTRAR-----\n");
  mostrar(socios,N,0);
  printf("-----MOSTRAR DNI(A)-----\n");
  mostrarDNI(socios,N,0);
  printf("-----ACTIVOS (A)-----\n");
  activos(socios,N,'A');
  printf("-----ACTIVOS (J)-----\n");
  activos(socios,N,'J');
  free(socios);
  return 0;
}

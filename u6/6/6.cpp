#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define CARREUNIDAT "CarreUni.dat"

typedef char Cadena[124];
typedef struct {
  int codigo;
  Cadena nombre;
  int anios;
  int cantInscriptos[4];
} Carrera;

void carga(FILE *c){
  int codigo, anio = 2018;
  Carrera aux;
  c = fopen(CARREUNIDAT, "wb");

  if(c == NULL){
    printf("carga() | c == NULL");
    return;
  }

  printf("codigo: ");
  scanf("%d", &codigo);

  while (codigo != 0){
    printf("nombre: ");
    gets(aux.nombre);

    printf("anios: ");
    scanf("%d", &aux.anios);

    for (int i = 0; i < 4; i++){
      printf("total inscriptos (%d): ", anio);
      scanf("%d",aux.cantInscriptos[i]);
      anio += 1;
    }

    fwrite(&aux,sizeof(aux),1, c);
    
    printf("codigo: ");
    scanf("%d", &codigo);
  }
  fclose(c);
}

void modifica(FILE *c){
  int codigo, anio;
  Carrera aux;
  c = fopen(CARREUNIDAT, "w+");

  if(c == NULL){
    printf("carga() | c == NULL");
    return;
  }

  printf("codigo: ");
  scanf("%d", &codigo);

  rewind(c);
  fread(&aux, sizeof(aux), 1, c);
  while(feof(c) == 0){
    if(aux.codigo == codigo){ 
      printf("anio a modificar (0: FIN):");
      scanf("%d", &anio);
      while (anio != 0) {
        if(codigo > 2018 && codigo < 2021){
          printf("nuevo valor: ");
          scanf("%d",aux.cantInscriptos[anio-2018]);
          fwrite(&aux,sizeof(aux),1,c);
        } else {
          printf("anio incorrecto\n");
        }
        printf("anio a modificar (0: FIN):");
        scanf("%d", &anio);
      }
      return;
    }
    fread(&aux, sizeof(aux), 1, c);
  }
  fclose(c);
}

void maximo(FILE *c){
  Cadena maxCarrera;
  int max=0;
  Carrera aux;

  c= fopen(CARREUNIDAT,"rb");

  if(c==NULL){
    printf("max() | c == NULL");
    return;
  }

  rewind(c);
  fread(&aux, sizeof(aux), 1, c);
  while (feof(c) == 0) {
    if(aux.cantInscriptos[2020-2018] > max){
      max = aux.cantInscriptos[2020-2018];
      strcpy(maxCarrera,aux.nombre);
    }
    fread(&aux, sizeof(aux), 1, c);
  }
  printf("inscriptos: %d, carrera: %s", max, maxCarrera);
  
}


int main(){
  FILE *carreras;
  printf("-----CARGA-----\n");
  carga(carreras);
  printf("-----MODIFICA-----\n");
  modifica(carreras);
  printf("-----MAX-----\n");
  maximo(carreras);
  return 0;
}
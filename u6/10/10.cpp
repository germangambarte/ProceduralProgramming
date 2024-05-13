#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#define MASVENTASDAT "MasVentas.dat"

typedef char Cadena[124];
typedef struct {
  int codigo;
  Cadena nombre;
  float precio;
  Cadena rubro;
  int stock;
} Producto;

void carga(FILE *e){
  Producto aux;
  int codigo = 0;
  e = fopen(MASVENTASDAT,"wb");

  if (e==NULL){
    printf("carga() | e == NULL");
    return;
  }

  printf("nombre ('FIN' para finalizar): ");
  gets(aux.nombre);
  while(stricmp(aux.nombre, "FIN") != 0){
    codigo += 1;
    aux.codigo = codigo;

    printf("rubro: ");
    gets(aux.rubro);

    printf("precio: ");
    scanf("%f", &aux.precio);

    printf("stock: ");
    scanf("%d", &aux.stock);

    fwrite(&aux,sizeof(aux),1,e);

    printf("nombre ('FIN' para finalizar): ");
    gets(aux.nombre);
  }
  fclose(e);
}

void mostrar(FILE *e){
  Producto aux;
  e = fopen(MASVENTASDAT,"rb");
  if (e == NULL){
    printf("mostrar() | e == NULL");
    return;
  }

  rewind(e);
  fread(&aux,sizeof(aux),1,e);
  while (feof(e)==0){
    printf(
      "nombre: %s, rubro: %s, precio: %d, stock: %d.\n",
      aux.nombre, aux.rubro, aux.precio, aux.stock
      );
    fread(&aux,sizeof(aux),1,e);
  }
  fclose(e);
}

void modifica(FILE *e, Producto aux, int p){
      aux.precio = (aux.precio * p / 100) + aux.precio;
      fseek(e,-sizeof(aux), SEEK_CUR);
      fwrite(&aux,sizeof(aux),1,e);
}

void actualizarPorCodigo(FILE *e){
  Producto aux;
  int codigo,porcentaje;

  printf("codigo: ");
  scanf("%d", &codigo);
  printf("porcentaje: ");
  scanf("%d", &porcentaje);

  rewind(e);
  fread(&aux,sizeof(aux),1,e);
  while (feof(e) == 0){
    if(aux.codigo == codigo){
      modifica(e,aux,porcentaje);
      return;
    }
  }
}

void actualizarPorRubro(FILE *e){
  Producto aux;
  int porcentaje;
  Cadena rubro;

  printf("rubro: ");
  gets(rubro);
  printf("porcentaje: ");
  scanf("%d", &porcentaje);

  rewind(e);
  fread(&aux,sizeof(aux),1,e);
  while (feof(e) == 0){
    if(strcmp(aux.rubro,rubro)==0){
      modifica(e,aux,porcentaje);
    }
  }
}

void actualizarYMostrar(FILE * e){
  e = fopen(MASVENTASDAT,"r+");
  if (e == NULL) {
    printf("actualizarYMostrar() | e == NULL");
    fclose(e);
    return;
  }
  for (int i = 0; i < 2; i++){
    actualizarPorCodigo(e);
  }
  for (int j = 0; j < 2; j++){
    actualizarPorRubro(e);
  }
  fclose(e);
  mostrar(e);
}

int mostrarMenu(){
  int opc;
  printf("-----MENU-----\n");
  printf("1. Mostrar Productos\n");
  printf("2. Actualizar Productos\n");
  printf("0. Finalizar\n");
  scanf("%d", &opc);
  system("cls");
  return opc;
}

int main(){
  FILE *empresa;
  int opcion;
  printf("-----CARGA-----\n");
  carga(empresa);
  opcion = mostrarMenu();
  while (opcion !=0) {
    switch (opcion){
      case 1:
        mostrar(empresa);
      break;
      case 2:
        actualizarYMostrar(empresa);
      break;
    }
    opcion = mostrarMenu();
  }
  return 0;
}
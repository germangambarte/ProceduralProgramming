#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define TITULOSDAT "titulos.dat"

typedef char Cadena[124];

typedef struct {
  int codigo;
  Cadena titulo;
  Cadena autor;
  int stock;
} Libro;

void carga(FILE *l){
  Libro aux;
  int codigo;
  l = fopen(TITULOSDAT, "wb");

  if(l == NULL){
    printf("carga () | l == NULL");
    return;
  }
  printf("codigo (0: FIN): ");
  scanf("%d", &codigo);
  while (codigo == 0) {

    aux.codigo = codigo;

    printf("titulo: ");
    gets(aux.titulo);
      
    printf("autor: ");
    gets(aux.autor);
      
    printf("stock: ");
    scanf("%d", &aux.stock);

    fwrite(&aux, sizeof(aux), 1, l);

    printf("codigo (0: FIN): ");
    scanf("%d", &codigo);
  }
  fclose(l);
}

int showMenu(){
	int opc;
	printf("\n-----MENU-----\n");
	printf("1. Stock por codigo.\n");
	printf("2. Autor por titulo.\n");
	printf("3. Libros por Autor.\n");
	printf("4. Agregar libro.\n");
	printf("0. Salir.\n");
	scanf("%d", &opc);
	system("cls");
	return opc;
}

void stockPorCodigo(FILE *l){
  Libro aux;
  int codigo;
  printf("codigo: ");
  scanf("%d", &codigo);
  l = fopen(TITULOSDAT, "rb");

  if(l == NULL){
    printf("stockPorCodigo() | l == NULL");
    return;
  }

  rewind(l);
  fread(&aux,sizeof(aux),1,l);
  while(feof(l) == 0){
    if(aux.codigo == codigo) {
      printf("titulo: %s, stock: %d", aux.titulo, aux.stock);
      return;
    }
    fread(&aux,sizeof(aux),1,l);
  }
  fclose(l);
}

void autorPorTitulo(FILE *l){
  Libro aux;
  Cadena titulo;

  printf("titulo: ");
  gets(titulo);

  l = fopen(TITULOSDAT, "rb");

  if(l == NULL){
    printf("stockPorCodigo() | l == NULL");
    return;
  }

  rewind(l);
  fread(&aux,sizeof(aux),1,l);
  while(feof(l) == 0){
    if(stricmp(aux.titulo, titulo) == 0){
      printf("autor: %s", aux.autor);
      return;
    }
    fread(&aux,sizeof(aux),1,l);
  }
  fclose(l);
}

void LibrosPorAutor(FILE *l){
  Libro aux;
  Cadena autor;

  printf("autor: ");
  gets(autor);

  l = fopen(TITULOSDAT, "rb");

  if(l == NULL){
    printf("stockPorCodigo() | l == NULL");
    return;
  }

  rewind(l);
  fread(&aux,sizeof(aux),1,l);
  while(feof(l) == 0){
    if(stricmp(aux.autor,autor)==0){
      printf("%s\n",aux.titulo);
    }
    fread(&aux,sizeof(aux),1,l);
  }
}

void agregarLibro(FILE *l){
  Libro aux;
  int cont = 0;

  l = fopen(TITULOSDAT, "ab");

  if(l == NULL){
    printf("stockPorCodigo() | l == NULL");
    return;
  }

  fseek(l, -sizeof(aux), SEEK_END);
  fread(&aux,sizeof(aux),1,l);
  aux.codigo +=1;

  printf("titulo: ");
  gets(aux.titulo);
  printf("autor: ");
  gets(aux.autor);
  printf("stock: ");
  scanf("%d", aux.stock);

  fwrite(&aux,sizeof(aux),1,l);

  printf("Libro agregado!\n");

  fclose(l);
}

int main(){
  FILE *libros;
  int opcion;
  printf("-----CARGA-----\n");
  carga(libros);
  opcion = showMenu();
  while(opcion != 0){
    switch (opcion)
    {
    case 1:
      stockPorCodigo(libros);
      break;
    
    case 2:
      autorPorTitulo(libros);
      break;
    case 3:
      LibrosPorAutor(libros);
      break;
    case 4:
      agregarLibro(libros);
      break;
    }
    opcion = showMenu();
  }
  return 0;
}
#include<stdio.h>
#include<string.h>
#define CADENA 100
#define CANTPROD 50
#define CANTPROV 22

typedef struct {
  int codigo;
  float precio;
  int stock;
} producto;

typedef struct {
  char nombre[CADENA];
  int numero; 
} proveedor;

void inicializar(producto pd[CANTPROD], proveedor pv[CANTPROV]){
  
}

void cargar_nombre(char n[CADENA]){
     printf("Ingrese nombre: ");
     gets(n);
     printf("%s",n);
}

int main(){
     producto productos[CANTPROD];
     proveedor proveedores[CANTPROV];
     cargar_nombre(nombre);
     return 0;
}

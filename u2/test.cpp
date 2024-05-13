#include<stdio.h>
#include<string.h>
#define CADENA 100

void cargar_nombre(char n[CADENA]){
     printf("nombre: ");
     gets(n);
     printf("mi nombre es %s\n",n);
}

void igualdad(char n[CADENA]){
     stricmp(n,"GERMAN") == 0 
      ? printf("Los nombres son iguales\n")
      : printf("Los nombres no son iguales\n");
}

int main(){
     char nombre[CADENA];
     cargar_nombre(nombre);
     igualdad(nombre);
     return 0;
}

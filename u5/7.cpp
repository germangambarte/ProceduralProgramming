#include<stdio.h>
#include<malloc.h>

typedef struct {
   char *nya;
   int pais_rec;
   int cant_goles;
}Jugador;

typedef struct {
   char *pais;
   int cant_estadios;
}Mundial;

typedef struct Puntero {
  Mundial *mundial;
  Jugador *jugadores;
  struct Puntero *sig;
} Nodo;

int main(){
  Jugador *jugadores;

  return 0;
}
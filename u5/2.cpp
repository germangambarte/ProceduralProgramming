#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define CDNI 8
#define CADENA 8

typedef struct {
  char dni[CDNI];
  int edad;
  char tipo;
  char estado[CADENA];
} socio;

void carga(socio *s, int N)
{
  char tipo;
  for (int i = 0; i < N; i++)
  {
    printf("tipo (A - B): ");
    scanf("%c", tipo);
    if(tipo == 'A' || tipo == 'B'){
      printf("dni: ");
      gets(s->dni);
      printf("edad: ");
      scanf("%d", &s->edad);
      printf("estado (Activo - Inactivo): ");
      gets(s->estado);
    } else {
      i--;
    }
  }
  
}

void mayores_de_40(socio *s, int c)
{
  int laux = 0, j = 0;
  socio *aux;
  for(int i = 0; i < c; i++)
  {
    if(s[i].tipo == 'A') laux += 1;
  }
  aux = (socio*) malloc(sizeof(socio*) * laux);
  for(int k = 0; k < laux; k++)
  {
    if(s[k].tipo == 'A') 
    {
      aux[j] = s[k];
      j += 1;
    }
  }
  for(int m = 0; m < laux; m++)
  {
    printf("dni: %s\n", aux[m].dni);
  }
  free(aux);
}

void activos(socio *s, int c, char t)
{
  int laux = 0, j = 0;
  socio *aux;
  for(int i = 0; i < c; i++)
  {
    if(stricmp(s[i].estado,"Activo") == 0 && s[i].tipo == t) laux += 1;
  }
  aux = (socio*) malloc(sizeof(socio*) * laux);
  for(int k = 0; k < laux; k++)
  {
    if(stricmp(s[k].estado,"Activo") == 0 && s[k].tipo == t)
    {
      aux[j] = s[k];
      j += 1;
    }
  }
  for(int m = 0; m < laux; m++)
  {
    printf("dni: %s, tipo: %c, se encuentra: %s\n", aux[m].dni, aux[m].tipo, aux[m].estado);
  }
  free(aux);
}

int main()
{
  socio *socios;
  int cantidad;
  printf("cantidad de socios: ");
  scanf("%d", &cantidad);
  socios = (socio *)malloc(sizeof(socio) * cantidad);
  printf("-----CARGA-----\n");
  carga(socios, cantidad);
  printf("-----MAYORES DE 40-----\n");
  mayores_de_40(socios, cantidad);
  printf("-----ACTIVOS TIPO A-----\n");
  activos(socios, cantidad, 'A');
  printf("-----ACTIVOS TIPO J-----\n");
  activos(socios, cantidad, 'J');
  free(socios);
  return 0;
}
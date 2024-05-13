#include<stdio.h>
#include<string.h>
#define CADENA 100
#define CANTAREAS 6
#define CANTCONFS 4
#define CANTSALAS 6

typedef struct 
{
  char nombre[CADENA];
  int cupo;
} area;

void carga_areas(area a[CANTAREAS])
{
  for (int i = 0; i < CANTAREAS; ++i)
  {
    printf("nombre de sala: ");
    gets(a[i].nombre);
    printf("cupos: ");
    scanf("%d", a[i].cupo);
  }
}

int buscar(area a[CANTAREAS], char nombre[CADENA])
{
  int i = CANTAREAS - 1;
  while(i > 0  && stricmp(a[i].nombre, nombre) != 0) i--
  return i
}

void procesar(area a[CANTAREAS], int c[CANTSALAS][CANTCONFS])
{
  char interesado[CADENA], sala[CADENA], conferencia;


  printf("nombre del interesado(0: salir): ");
  gets(interesado);
  while(stricmp(interesado,"0")!=0)
  {
    printf("nombre de sala: ");
    gets(sala);
    printf("conferencia\n");
    scanf("%d", &conferencia);

    int indice = buscar(a,sala)


    if (indice != -1 && a[indice].cupo != 0) 
    {
      a[indice].cupo -= 1;
      c[indice][conferencia - 1] += 1;
    } else
    {
      printf("no hay cupo o el nombre de la sala no es correcto\n");
    }
    printf("nombre del interesado(0: salir): ");
    gets(interesado);
  }
}

void asistentes(areas a[CANTAREAS], int c[CANTSALAS][CANTCONFS])
{
  int min = 9999999, max = 0, i_min, i_max;
  for (int i = 0; i < CANTSALAS; ++i)
  {
    for (int j = 0; j < CANTCONFS; ++j)
    {
      if (c[i][j] < min)
      {
        min = c[i][j];
        i_min = j;
      }
      if (c[i][j] > max)
      {
        max = c[i][j];
        i_max = j;
      }
    }
    printf("sala %s:\n", a[i].nombre);
    printf("  min: conferencia %d \n", i_min + 1);
    printf("  max: conferencia %d \n", i_max + 1);
    min = 99999999;
    max = 0;
  }
}

void cantidades(int c[CANTSALAS][CANTCONFS])
{
  int min = 9999999, max = 0, sum = 0;
  for (int i = 0; i < CANTSALAS; ++i)
  {
    for (int j = 0; j < CANTCONFS; ++j)
    {
      sum += c[i][j];
    }
    if(sum < min) min = sum;
    if(sum > max) max = sum;
    sum = 0;
  }
  printf("min inscriptos: %d \n", min);
  printf("max inscriptos: %d \n", max);
}

void menos_inscriptos(area a[CANTAREAS], int c[CANTSALAS][CANTCONFS])
{
  int min = 9999999, i_min, sum = 0;
  for (int i = 0; i < CANTSALAS; ++i)
  {
    for (int j = 0; j < CANTCONFS; ++j)
    {
      sum += c[i][j];
    }
  if(sum < min) 
  {
    min = sum;
    i_min = i
  }
  sum = 0;
  }
  printf("sala con menos inscriptos: %s \n", a[i_min].nombre);
}

void promedio_por_nombre(area a[CANTAREAS], int c[CANTSALAS][CANTCONFS])
{
  char sala[CADENA];
  int indice, sum = 0, cont = 0;
  float prom;
  printf("sala: ");
  gets(sala);
  indice = buscar(a, sala);
  if(indice != -1)
  {
    for (int j = 0; j < CANTCONFS; ++j)
    {
      sum += c[indice][j];
      cont += 1;
    }
    prom = sum / cont;
    printf("promedio de la sala %s: %.2f\n", sala, prom);
  }
}

void sin_turnos(area a[CANTAREAS])
{
  for (int i = 0; i < CANTAREAS; ++i)
  {
    if(a[i].cupo == 0) printf("la sala de %s, esta completa\n", a[i].nombre);
  }
}

int main()
{
  area areas[CANTAREAS];
  int conferecias[CANTSALAS][CANTCONFS];


  printf("-----CARGA AREAS-----\n");
  carga_areas(areas);
  printf("-----PROCESAR-----\n");
  procesar(areas, conferencias);
  printf("-----ASISTENTES-----\n");
  asistentes(areas,conferecias)
  printf("-----CANTIDADES-----\n");
  cantidades(conferecias);
  printf("-----MENOS INSCRIPTOS-----\n");
  menos_inscriptos(areas,conferecias);
  printf("-----PROMEDIO-----\n");
  promedio_por_nombre(areas,conferecias);
  return 0;
}



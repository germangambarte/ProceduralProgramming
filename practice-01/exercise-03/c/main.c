#include <stdio.h>
#include <strings.h>
#define N 3
#define M 20

struct Student
{
  char name[M];
  char lastname[M];
  int dni;
};

void load(struct Student x[N])
{
  for (int i = 0; i < N; i++)
  {
    printf("Nombre: ");
    fgets(x[i].name, sizeof(char) * M, stdin);
    printf("Apellido: ");
    fgets(x[i].lastname, sizeof(char) * M, stdin);
    printf("Dni: ");
    scanf("%d", &x[i].dni);
    while (getchar() != '\n');
  }
}

void show(struct Student x[N])
{
  for (int i = 0; i < N; i++)
    printf("nombre: %s apellido: %s dni: %d\n", x[i].name, x[i].lastname, x[i].dni);
}

void count(struct Student x[N])
{
  int count = 0;
  for (int i = 0; i < N; i++)
  {
    if (x[i].dni > 40000000)
      count++;
  }
  printf("Cantidad de DNIs mayores a 40M: %d", count);
}

void main()
{
  struct Student students[N];
  load(students);
  printf("\n");
  show(students);
  printf("\n");
  count(students);
}
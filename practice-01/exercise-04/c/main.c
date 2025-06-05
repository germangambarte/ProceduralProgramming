#include <stdio.h>
#define N 4
#define M 20

struct Candidate
{
  char name[M];
  char genre;
  int dni;
  int age;
  int code;
};

void load(struct Candidate x[N])
{
  for (int i = 0; i < N; i++)
  {
    printf("Nombre: ");
    fgets(x[i].name, sizeof(char) * M, stdin);
    printf("Genero: ");
    scanf("%c", &x[i].genre);
    printf("DNI: ");
    scanf("%d", &x[i].dni);
    printf("Edad: ");
    scanf("%d", &x[i].age);
    printf("Codigo: ");
    scanf("%d", &x[i].code);

    while (getchar() != '\n')
      ;
    printf("\n");
  }
}

void womenCounter(struct Candidate x[N])
{
  int count = 0;
  for (int i = 0; i < N; i++)
  {
    if (x[i].genre == 'F' && x[i].age < 30)
    {
      count++;
    }
  }
  printf("Cantidad de mujeres: %d", count);
}

void averageMenAge(struct Candidate x[N])
{
  int count = 0;
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    if (x[i].genre == 'M')
    {
      sum += x[i].age;
      count++;
    }
  }
  printf("Edad promedio de varones: %.2f", (float)(sum / count));
}

void printCandidates(struct Candidate x[N])
{
  for (int i = 0; i < N; i++)
  {
    if (x[i].code == 14)
    {
      printf("candidato: %s, dni:%d\n", x[i].name, x[i].dni);
    }
  }
}

void main()
{
  struct Candidate candidates[N];
  load(candidates);
  printf("\n");
  womenCounter(candidates);
  printf("\n");
  averageMenAge(candidates);
  printf("\n");
  printCandidates(candidates);
}
#include <stdio.h>
#include <string.h>
#define M 50
#define N 3

struct Article
{
  int code;
  char name[M];
  float unitary_price;
  int stock;
};

void load(struct Article x[])
{
  for (int i = 0; i < N; i++)
  {
    printf("Codigo: ");
    scanf("%d", &x[i].code);
    printf("Nombre: ");
    fgets(x[i].name, sizeof(char) * M, stdin);
    while (getchar() != '\n')
      ;
    printf("Precio unitario: ");
    scanf("%f", &x[i].unitary_price);
    printf("Stock: ");
    scanf("%d", &x[i].stock);
    printf("\n");
  }
}

int searchByCode(struct Article x[], int code)
{
  int i = 0;
  while (i < N && x[i].code != code)
    i++;
  return i;
}

int searchByName(struct Article x[], char *name)
{
  int i = 0;

  name[strcspn(name, "\n")] = '\0';
  while (i < N && strcasecmp(x[i].name, name) != 0)
    i++;
  return i;
}

void process(struct Article x[])
{
  char articleName[M];
  int amount;

  printf("Nombre del producto: ");
  fgets(articleName, sizeof(char) * M, stdin);
  articleName[strcspn(articleName, "\n")] = '\0';

  while (strcasecmp(articleName, "FIN") != 0)
  {
    printf("Cantidad de unidades vendidas: ");
    scanf("%d", &amount);
    while (getchar() != '\n')
      ;

    int idx = searchByName(x, articleName);

    if (idx < N)
    {
      x[idx].stock -= amount;
    }
    else
    {
      printf("No econtrado.\n");
    }

    printf("Nombre del producto: ");
    fgets(articleName, sizeof(char) * M, stdin);
    articleName[strcspn(articleName, "\n")] = '\0';
  }
}

void checkEmptyStock(struct Article x[])
{
  printf("Articulos sin stock:\n");
  for (int i = 0; i < N; i++)
  {
    if (x[i].stock == 0)
    {
      printf("  - %s\n", x[i].name);
    }
  }
}

void showStock(struct Article x[])
{
  int code;
  printf("Ingrese el codigo: ");
  scanf("%d", &code);

  int idx = searchByCode(x, code);
  if (idx < N)
  {
    printf("Stock: %d", x[idx].stock);
  }
  else
  {
    printf("No econtrado.");
  }
}

void main()
{
  // struct Article articles[N];
  struct Article articles[N] = {
      {101, "Lapicera", 150.50, 20},
      {102, "Cuaderno", 300.00, 10},
      {103, "Regla", 120.75, 0}};

  // load(articles);
  // printf("\n");
  process(articles);
  printf("\n");
  checkEmptyStock(articles);
  printf("\n");
  showStock(articles);
}
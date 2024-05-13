#include <stdio.h>

const int MAX_PRODUCT = 50;
const int MAX_SUPPLIER = 22;

typedef struct 
{
  int code;
  float price;
  int stock;
}product;

typedef struct 
{
  char name[256];
  int supplier_code;
  int purchase_count;
}supplier;

typedef struct 
{
  int supplier_code;
  int product_code;
  int units;
} purchase;


void load(product p[MAX_PRODUCT], supplier s[MAX_SUPPLIER])
{
  for (int i = 0; i < MAX_PRODUCT; i++)
  {
    printf("ingrese el codigo del producto:\n");
    scanf("%d", &p[i].code);
    printf("ingrese el precio del producto:\n");
    scanf("%d", &p[i].price);
    printf("ingrese el stock del producto:\n");
    scanf("%d", &p[i].stock);
  }
  for (int i = 0; i < MAX_SUPPLIER; i++)
  {
    printf("ingrese el precio del producto:\n");
    scanf("%d", &s[i].name);
    printf("ingrese el codigo del producto:\n");
    scanf("%d", &s[i].supplier_code);
    s[i].purchase_count = 0;
  }
}

void load_purchases(product p[MAX_PRODUCT], supplier s[MAX_SUPPLIER])
{
  int sup_code,prod_code,quantity;
  printf("ingrese el codigo del proveedor, para finalizar ingrese '0'\n");
  scanf("%d", &sup_code);
  while (sup_code > 0)
  {
    printf("ingrese el codigo del producto\n");
    scanf("%d", &prod_code);
    printf("ingrese la cantidad de unidades compradas\n");
    scanf("%d", &quantity);
    s[sup_code - 1000].purchase_count = s[sup_code - 1000].purchase_count + 1;
    p[prod_code - 1].stock = p[prod_code - 1].stock + quantity;

    printf("ingrese el codigo del proveedor, para finalizar ingrese '0'\n");
    scanf("%d", &sup_code);
  }
}

void investment_per_product(product p[MAX_PRODUCT])
{
  for (int i = 0; i < MAX_PRODUCT; i++)
  {
    printf("En el producto %d se invitió un total de $%f\n", p[i].code,p[i].price * p[i].stock);
  }
}

int plus_ten_purchases(supplier s[MAX_SUPPLIER], supplier fs[MAX_SUPPLIER])
{
  int j = 0;
  for (int i = 0; i < MAX_SUPPLIER; i++)
  {
    if(s[i].purchase_count > 10)
    {
      fs[j] = s[i];
      j = j++;
    }
  }
  return j;
}

void show(supplier s[MAX_SUPPLIER], int C)
{
  for (int i = 0; i < C; i++)
  {
    printf("A los siguientes proveedores se les realizo mas de 10 compras\n");
    printf("nombre: %s, codigo: %d, cantidad de compras: %d\n", s[i].name,s[i].supplier_code,s[i].purchase_count );
  }
  
}

void order_list(supplier s[MAX_SUPPLIER], int C)
{
  int k,cota;
  supplier aux;
  cota = C -1;
  k = 1;
  while(k != -1)
  {
    k = -1;
    for (int i = 0; i < cota; i++)
    {
      if(s[i].name > s[i+1].name)
      {
        aux = s[i];
        s[i] = s[i + 1];
        s[i + 1] = aux;
        k = i;
      }
    }
    cota = k;
  }
  show(s,C);
}

void search(supplier s[MAX_SUPPLIER])
{
  
}

int main()
{
  product products[MAX_PRODUCT];
  supplier suppliers[MAX_SUPPLIER];
  supplier filter_suppliers[MAX_SUPPLIER];
  int C;
  load(products,suppliers);
  load_purchases(products,suppliers);
  C = plus_ten_purchases(suppliers, filter_suppliers);
  order_list(filter_suppliers,C);
  search(suppliers);
  return 0;
}

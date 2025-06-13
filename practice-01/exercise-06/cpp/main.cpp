#include <iostream>
#include <string>
#define N 3

using namespace std;

struct Product
{
  int id;
  float price;
  int stock;
};

struct Provider
{
  string algo;
  int id;
  int purchases;
};

int searchProductById(Product prods[], int id)
{
  int i = 0;
  while (i < N && prods[i].id != id)
    i++;
  return i;
}

int searchProviderById(Provider provs[], int id)
{
  int i = 0;
  while (i < N && provs[i].id != id)
    i++;
  return i;
}

void process(Product prods[], Provider provs[], int prodId, int provId, int units)
{
  int prodIndex = searchProductById(prods, prodId);
  int provIndex = searchProviderById(provs, provId);
  prods[prodIndex].stock -= units;
  provs[provIndex].purchases += units;
}

void processPurchases(Product prods[], Provider provs[])
{
  int provId, prodId, units;
  cout << "Id de proveedor: ";
  cin >> provId;
  while (provId != 0)
  {
    cout << "Id de producto: ";
    cin >> prodId;
    cout << "Unidades compradas: ";
    cin >> units;

    process(prods, provs, prodId, provId, units);

    cout << "Id de proveedor: ";
    cin >> provId;
  }
}

void showInvestment(Product prods[])
{
  for (int i = 0; i < N; i++)
  {
    int investment = prods[i].price * prods[i].stock;
    printf("Producto %d, inversion: %.2f", prods[i].id, investment);
  }
}

void filter(Provider provs[], Provider *altProvs, int *M)
{
  for (int i = 0; i < N; i++)
  {
    if (provs[i].purchases >= 3)
    {
      altProvs[*M++] = provs[i];
    }
  }
}

void sortArray(Provider altProvs,int M){
  Provider temp;

  
}

void showNewArray(Provider altProvs[], int M){

}

int main()
{
  Product products[N];
  Provider providers[N];
  return 0;
}
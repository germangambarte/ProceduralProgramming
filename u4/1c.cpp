#include <stdio.h>

int funcionC (int x[], int n, int dato)
{
  if (n==0)
  {
    if (dato > x[n])
      return x[0];
    else
      return dato;
  }
  else
  {
    if (dato > x[n])
      return funcionC(x,n-1, x[n]);
    else
      return funcionC(x, n-1, dato);
  }
}

int main ()
{
  int x[] = {25, 18, 56, 35};
  int n =3;
  int dato = 50;
  int result = funcionC(x,n,dato);
  printf("result: %d\n", result);
  return 0;
}

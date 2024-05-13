#include <stdio.h>

void funcionA(int n)
{
  if(n)
  {
    printf("%d\n", n%10);
    n=(int)n/10;
    funcionA(n);
  }
}

int main()
{
  int n = 6745;
  funcionA(n);
  return 0;
}

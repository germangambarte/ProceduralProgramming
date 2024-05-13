#include <stdio.h>

int funcionB (int n)
{
  if(n == 0)
    return n;
  else
  {
    return funcionB(n/10) + (n%10);
  }
}

int main ()
{
  int n = 5679, result;
  result = funcionB(n);
  printf("result: %d\n", result);
  return 0;
}

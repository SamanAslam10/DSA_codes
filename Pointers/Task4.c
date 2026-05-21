#include <stdio.h>

void B(int b)
{ 
    printf("%d ", b);
}

void A(int a)
{
    B(a*2); 
    printf("%d ", a); 
}

int main()
{
  int x = 5;
  A(x);
}

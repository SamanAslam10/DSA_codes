#include <stdio.h>

int sum(int n);
int sumHelper(int n , int depth);
int calls;
int depth;

int main()
{
    int n = 5;
    int result = sum(n);

    printf("Sum = %d\n" , result);
    printf("Recursive Calls = %d\n", calls);
    printf("Depth = %d\n", depth);
}
int sum(int n)
{
    calls = 0;
    depth = 0;

    return sumHelper(n , 1);
}
int sumHelper(int n , int currentdepth)
{
    if(n == 0)
    {
        return 0;
    }
    calls ++;
    depth = currentdepth;
    return n + sumHelper(n-1 , currentdepth + 1);
}
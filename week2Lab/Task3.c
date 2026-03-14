#include <stdio.h>
void swap(int *a , int *b);
int main()
{
    int x = 10;
    int *px = &x;
    int y = 20;
    int *py = &y;

    printf("%s", "Values before swap : x = ");
    printf("%d" , *px);
    printf("%s", ", y = ");
    printf("%d" , *py);
    swap( px , py);

    printf("%s", " and Values after swap : x = ");
    printf("%d" , *px);
    printf("%s", ", y = ");
    printf("%d" , *py);
    return 0;
}
void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
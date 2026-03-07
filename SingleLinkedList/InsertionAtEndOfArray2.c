#include <stdio.h>
#include <stdlib.h>
// array is already full
int addAtEnd(int a[] , int b[] , int free, int data , int n);
int main()
{
    int arr[4];
    int n, i;
    int free;
    printf("Enter the number of Elemets ");
    scanf("%d", &n);

    for(i = 0 ; i<n ; i++)
    { 
        printf("Enter the of Elemet : ");
        scanf("%d", &arr[i]);
    }
    int size = sizeof(arr)/sizeof(arr[0]);
    free = n;
    if(n == size)
    {
        int arr2[n + 2];
        free = addAtEnd(arr , arr2 , free , 65 , n);

        for(int i = 0 ; i<free ; i++)
        {
            printf("%d,%s", arr2[i] , "  " );
        }
    }
    return 0;
}
int addAtEnd(int a[] , int b[] , int free, int data , int n)
{
    int i = 0;
    for( i = 0; i<n ; i++)
    {
        b[i] = a[i];
    }
    b[free] = data;
    free ++;
    return free;
}
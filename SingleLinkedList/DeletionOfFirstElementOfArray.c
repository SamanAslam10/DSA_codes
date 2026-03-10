#include <stdlib.h>
#include <stdio.h>
int DeleteFirstElement(int arr[] , int n);
int main()
{
    int n;
    printf("%s" , " Enter the no. of elements u want to enter : ");
    scanf("%d" , &n);
    int array[n];

    for(int i = 0 ; i < n ; i ++)
    {
        printf("%s" , "Enter the element : ");
        scanf("%d" , &array[i]);
    }
    
    n = DeleteFirstElement(array , n);
    for (int i = 0; i < n; i++)
    {
        printf("%d,%s" , array[i] , "   ");
    }
    
    return 0;
}
int DeleteFirstElement(int arr[] , int n)
{
    for(int i = 0 ; i < n ; i ++)
    {
        arr[i] = arr[i+1]; 
    }
    return n - 1;
}
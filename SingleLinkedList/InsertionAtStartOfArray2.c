#include <stdio.h>
#include <stdlib.h>

int InsertAtStart(int arr[] , int arr2[] , int data , int n);
int main()
{
    int arrSize = 3;
    int arr[arrSize];
    int n , i;

    int arrSize2 = arrSize + 2;
    int arr2[arrSize2];

    printf("Enter the number of Elemets ");
    scanf("%d", &n);

    for(i = 0 ; i<n ; i++)
    { 
        printf("Enter Element : ");
        scanf("%d", &arr[i]);
    }

    int size = sizeof(arr)/sizeof(arr[0]);
    if(size == arrSize)
    {
        n = InsertAtStart(arr , arr2 , 24 , n);
    }

    for(int a = 0 ; a < n ; a ++)
    {
        printf("%d,%s" , arr2[a] , "  ");
    }
}
int InsertAtStart(int arr[] , int arr2[] , int data , int n)
{
    for(int s = n-1; s >=0 ; s --)
    {
        arr2[s+1] = arr[s];
    }
    arr2[0] = data;
    return n + 1;
}
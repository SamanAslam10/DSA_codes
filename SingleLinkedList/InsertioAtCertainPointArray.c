#include <stdio.h>
#include <stdlib.h>

int InsertAtCertainPoint(int arr[] , int arr2[] , int data , int n , int pos);
int main()
{
    int arrSize = 3;
    int arr[arrSize];
    int n , i;

    int arrSize2 = arrSize + 1;
    int arr2[arrSize2];

    printf("Enter the number of Elemets ");
    scanf("%d", &n);

    for(i = 0 ; i<n ; i++)
    { 
        printf("Enter Element : ");
        scanf("%d", &arr[i]);
    }

    int size = sizeof(arr)/sizeof(arr[0]);
    int pos = 2;
    
    if(size == arrSize)
    {
        InsertAtCertainPoint(arr , arr2 , 24 , n , pos );
    }

    for(int a = 0 ; a < arrSize2 ; a ++)
    {
        printf("%d,%s" , arr2[a] , "  ");
    }
}
int InsertAtCertainPoint(int arr[] , int arr2[] , int data , int n , int pos)
{
    int x;
    int index = pos -1;
    for(x = 0 ; x <= index ; x++)
    {
        arr2[x] = arr[x];
    }
    arr2[pos] = data;
    int index2 = pos + 1;
    for(int y = index2; y <= n ; y ++)
    {
        arr2[y] = arr[y-1];
    }
}
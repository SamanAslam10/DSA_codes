#include <stdio.h>

int removeDuplicates(int arr[], int n)
{
    int j=0;

    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[j])
        {
            j++;
            arr[j]=arr[i];
        }
    }

    return j+1; // new length
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 5, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    n = removeDuplicates(arr, n);

    printf("Array after removing duplicates: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
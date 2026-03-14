#include <stdio.h>

void rotate(int arr[], int n, int k)
{
    for(int r=0; r<k; r++)
    {
        int temp = arr[0];

        for(int i=0; i<n-1; i++)
            arr[i] = arr[i+1];

        arr[n-1] = temp;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;

    printf("Enter number of rotations: ");
    scanf("%d", &k);

    rotate(arr, n, k);

    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
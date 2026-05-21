#include <iostream>

using namespace std;

void SelectionSort(int A[] , int n)
{
    int i,j,k;
    for(i = 0 ; i < n-1; i++)
    {
        for(j=k=i; j < n ; j ++)
        {
            if(A[j] < A[k])
            {
                k=j;
            }
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}
void Print(int A[] , int n)
{
    for(int i = 0 ; i < n ; i ++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n = 6;
    int A[n] = {8,6,3,2,5,4};

    Print(A,n);
    SelectionSort(A,n);
    Print(A,n);
    return 0;
}
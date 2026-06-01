#include <iostream>

using namespace std;

void InsertionSort(int A[] , int n)
{
    int comp = 0;
    int swap = 0;
    for(int i = 1 ; i < n ; i ++)
    {
        int j = i-1;
        int x = A[i];

        while(j > -1)
        {
            comp ++;
            if(A[j] > x)
            {
                A[j+1] = A[j];
                j --; 
                swap ++;
            }
            else
            {
                break;
            }
        }
        A[j+1] = x;
    }
    cout<<"Comparisons: "<<comp<<endl<<" Swaps: "<<swap;
}
int main()
{
    int n = 5;
    int A[n] = {1,2,3,4,5};
    InsertionSort(A,n);
    return 0;
}
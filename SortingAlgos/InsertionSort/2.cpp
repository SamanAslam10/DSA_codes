#include <iostream>

using namespace std;

int main()
{   
    int n = 5;
    int A[n] = {8,4,1,9,3};

    int partition = 0;
    for(int i = 1 ; i < n ; i ++)
    {
        int j = 
        for(int j = partition ; j <= 0 ; j --)
        {
            if(A[i] < A[j] )
            {
                int temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }
    }
    for(int i = 0; i < n ; i ++)
    {
        int 
    }

    for(int i = 0 ; i < n ; i ++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
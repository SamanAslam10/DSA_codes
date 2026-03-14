#include <stdio.h>

int main()
{
    int A[]={1,4,7,10};
    int B[]={2,3,9};

    int m=4,n=3;

    int C[10];

    int i=0,j=0,k=0;

    while(i<m && j<n)
    {
        if(A[i]<B[j])
            C[k++]=A[i++];
        else
            C[k++]=B[j++];
    }

    while(i<m)
        C[k++]=A[i++];

    while(j<n)
        C[k++]=B[j++];

    for(int x=0;x<k;x++)
        printf("%d ",C[x]);
}
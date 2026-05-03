#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the no of Nodes: ";
    int n = 0;
    cin>>n;

    int A[n];
    cout<<"Enter the Elements Level wise : "<<endl;

    for(int i = 0 ; i < n ; i ++)
    {
        cout<<i<<". ";
        cin>>A[i];
    }
    return 0;
}
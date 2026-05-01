#include <iostream>

using namespace std;

void Print(int Tree[] , int nodes)
{
    for(int i = 0 ; i < nodes; i ++)
    {
        cout<<Tree[i]<<" left -> ";
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < nodes)
        {
            cout<<Tree[left]<<" right -> ";
        }
        if(right < nodes)
        {
            cout<<Tree[right]<<endl;
        }
    }
}
int main()
{
    int nodes;
    cout<<"No Of Nodes: ";
    cin>>nodes;

    int Tree[nodes];

    for(int i = 0 ; i < nodes ; i ++)
    {
        cout<<"Node "<<i<<" : ";
        cin>>Tree[i];
    }

    Print(Tree,nodes);

}


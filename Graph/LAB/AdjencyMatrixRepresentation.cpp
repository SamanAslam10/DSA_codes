#include <iostream>

using namespace std;

int main()
{
    int edges , nodes;
    cout<<"Enter the no. of nodes : ";
    cin>>nodes;

    cout<<"Enter the no. of edges: ";
    cin>>edges;

    int Matrix[nodes][nodes] = {0};

    int node1 , node2;
    for(int i = 0; i < edges ; i ++ )
    {
        cout<<"1st node : ";
        cin>>node1;
        cout<<"2nd node : ";
        cin>>node2;

        Matrix[node1][node2] = 1;
        Matrix[node2][node1] = 1;
    }

    for(int i = 0 ; i < nodes ; i ++)
    {
        for(int j = 0 ; j < nodes ; j ++)
        {
            cout<<Matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

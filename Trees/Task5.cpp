#include <iostream>

using namespace std;

int main()
{
    int n;

    cout<<"Enter number of nodes: ";
    cin>>n;

    int Tree[n];
    cout<<"Enter the value of Nodes level wise: ";
    for(int i = 0 ; i < n ; i ++)
    {
        cin>>Tree[i];
    }

    for(int i = 0 ; i < n ; i ++)
    {
        cout<<"Node : "<<Tree[i]<<endl;

        int leftchild =2*i + 1;
        int rightchild = 2*i + 2;

        if(leftchild > n)
        {
            cout<<"Left: NULL"<<endl;
        }
        else
        {
            cout<<"Left: "<<Tree[leftchild]<<endl;
        }

        if(rightchild > n)
        {
            cout<<"right: NULL"<<endl;
        }
        else
        {
            cout<<"right: "<<Tree[rightchild]<<endl;
        }

        cout<<endl;
    }
    return 0;
}
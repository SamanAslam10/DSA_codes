#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
Node* CreateNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}
void addEdge(Node* addList[],int u , int v)
{
    Node* newNode = CreateNode(v);
    newNode->next = 
}
int main()
{
    int edges , nodes;
    cout<<"Enter the no. of nodes : ";
    cin>>nodes;

    cout<<"Enter the no. of edges: ";
    cin>>edges;

    int *Array[nodes];

    int node1 , node2;
    for(int i = 0; i < edges ; i ++ )
    {
        cout<<"1st node : ";
        cin>>node1;
        cout<<"2nd node : ";
        cin>>node2;

        if(i == node1)
        {
            
        }
    }
    
    return 0;
}
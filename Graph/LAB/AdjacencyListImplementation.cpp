#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
#define n 8
struct Node *A[n];

Node* CreateNode(int value)
{
    struct Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    return temp;
}
void AddEdge(int index, int node)
{
    Node* temp = CreateNode(node);
    temp->next = A[index];
    A[index] = temp;
}
void Print()
{
    for(int i = 0 ; i < n ; i ++)
    {
        cout<<i<<"-> ";
        Node* temp = A[i];
        while(temp != NULL)
        {
            cout<<temp->data<<",";
            temp = temp -> next;
        }
        cout<<endl;
    }
}

int main()
{
    for(int i = 0 ; i < n ; i ++)
    {
        A[i] = NULL;
    }

    AddEdge(0,1);
    AddEdge(0,2);

    AddEdge(1,0);
    AddEdge(2,0);

    Print();
    return 0;
}
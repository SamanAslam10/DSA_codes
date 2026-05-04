#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};
#define n 3
struct Node *A[n];
Node* CreateNode(int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    return temp;
}
void AddEdje(int idx , int node)
{
    Node* temp = CreateNode(node);
    temp->next = A[idx];
    A[idx] = temp;
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
            temp=temp->next;
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

    AddEdje(0,1);
    AddEdje(0,2);
    AddEdje(1,0);
    AddEdje(2,0);


    Print();
    return 0;
}
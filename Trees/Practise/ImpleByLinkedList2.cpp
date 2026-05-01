#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data=value;
        left = NULL;
        right = NULL;
    }
};

void Print(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";

    Print(root->left);
    Print(root->right);
}
int main()
{
    Node* root = new Node(10);
    
    Node* c1 = new Node(20);
    Node* c2 = new Node(30);

    root->left = c1;
    root->right = c2;

    Node* c3 = new Node(40);
    Node* c4 = new Node(50);

    c1->left = c3;
    c1->right = c4;

    Print(root);
    return 0;
}
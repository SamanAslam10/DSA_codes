#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void PreOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    PreOrder(root->left);
    cout<<root->data<<" ";
    PreOrder(root->right);
}
void InOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    InOrder(root->left);
    InOrder(root->right);
}
void PostOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    PostOrder(root->right);
    cout<<root->data<<" ";
    PostOrder(root->left);
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
    Node* c5 = new Node(60);
    Node* c6 = new Node(70);

    c1->left = c3;
    c1->right = c4;

    c2->left = c5;
    c2->right = c6;


    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PreOrder(root);
    return 0;
}
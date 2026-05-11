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

Node* Insert(Node* root, int value)
{
    if(root == NULL)
    {
        return new Node(value);
    }
    if(value > root->data)
    {
        root->right = Insert(root->right , value);
    }
    else if(value < root->data)
    {
        root->left = Insert(root->left , value);
    }
    return root;
}
void InOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" , ";
    InOrder(root->right);
}
void PreOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" , ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void PostOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    PostOrder(root->right);
    cout<<root->data<<" , ";
    PostOrder(root->left);
}
void PreOrder(){}
void PostOrder(){}
int main()
{
    Node* root = NULL;
    root = new Node(45);
    Insert(root,25);
    Insert(root,65);
    Insert(root,15);
    Insert(root,35);
    Insert(root,55);
    Insert(root,75);


    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PostOrder(root);

    return 0;
}
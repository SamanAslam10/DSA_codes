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
void Delete(Node* root,int value)
{
    if(root == NULL)
    {
        return;
    }
    if(root->data == value)
    {

        root == NULL;
        root->left = root ->left ->left;

    }
    if(root->data > value)
    {
        Delete(root->right,value);
    }
    else if(root->data < value)
    {
        Delete(root->left,value);
    }
}
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

    Delete(root,75);
    
    PostOrder(root);

    return 0;
}
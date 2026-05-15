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

Node* Create(int data)
{
    Node* node = new Node(data);
    node->left = NULL;
    node->left = NULL;

    return node;
}
Node* Insert(Node* root , int data)
{
    if(root == NULL)
    {
        return Create(data);
    }

    if(data > root->data)
    {
        root->right = Insert(root->right,data);
    }
    else if(data < root->data)
    {
        root->left = Insert(root->left,data);
    }

    return root;
}
Node* Search(Node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == key)
    {
        return root;
    }
    if(key > root->data)
    {
        return Search(root->right,key);
    }
    else if(key < root->data)
    {
        return Search(root->left,key);
    }
}
int main()
{
    Node* root = new Node(45);

    Insert(root,25);
    Insert(root,65);
    Insert(root,15);
    Insert(root,35);
    Insert(root,55);
    Insert(root,75);

    Node* search = Search(root , 55);
    if(search != NULL)
    {
        cout<<search->data<<" Found";
    }
    else
    {
        cout<<"Not Found";
    }
    return 0;
}
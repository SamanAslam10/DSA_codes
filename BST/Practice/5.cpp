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
        right= NULL;
    }
};

Node* CreateNode(int data)
{
    Node* node = new Node(data);
    node->left = NULL;
    node->right = NULL;

    return node;
}
Node* Insert(Node* root,int data)
{
    Node* newNode = CreateNode(data);

    if(root == NULL)
    {
        return newNode;
    }
    if(data < root->data)
    {
        root->left = Insert(root->left , data);
    }
    else if(data > root->data)
    {
        root->right = Insert(root->right,data);
    }

    return root;
}
int Left(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int count=0;
    count += Left(root->left);

    return count+1;
}
int Right(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int count=0;
    count += Right(root->right);

    return count+1;
}
int Total(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    int Total = Right(root) + Left(root);

    return Total +1;
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

    cout<<Total(root);
    return 0;
}
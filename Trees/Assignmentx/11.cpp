#include <iostream>
#include <stack>

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
Node* LCA(Node* root , int n1 , int n2)
{
    while(root != NULL)
    {
        if(root->data > n1 && root->data > n2)
        {
            root = root->left;
        }
        else if(root->data < n1 && root->data < n2)
        {
            root = root->right;
        }
        else break;
    }
    return root;
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

    Node* lca = LCA(root,15,35);
    cout<<lca->data;
    return 0;
}
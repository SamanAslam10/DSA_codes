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
void Inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
int LeftHeight(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int count = 0;
    count += LeftHeight(root->left);

    return count + 1;
}
int RightHeight(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int count = 0;
    count += RightHeight(root->left);

    return count + 1 ;
}
int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return max(LeftHeight(root),RightHeight(root));
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

    
    cout<<height(root);
    return 0;
}
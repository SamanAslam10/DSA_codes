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

Node* Insert(Node* root,int data)
{
    if(root == NULL)
    {
        return new Node(data);
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
Node* Search(Node* root, int value)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->data == value)
    {
        return root;
    }
    else if(root->data > value)
    {
        return Search(root->left,value);
    }
    else
    {
        return Search(root->right,value);
    }
}
void Inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout<<root->data<<"  ";
    Inorder(root->right);
}
int Min(Node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}
int Max(Node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    while(root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}
int main()
{
    Node* root = new Node(100);
    Insert(root,50);
    Insert(root,150);
    Insert(root,30);
    Insert(root,70);
    Insert(root,120);
    Insert(root,170);
    Insert(root,20);
    Insert(root,40);
    Insert(root,60);
    Insert(root,80);

    Inorder(root);
    cout<<endl;

    cout<<"Enter the value you want to Search: ";
    int search = 0;
    cin>>search;

    Node* found = Search(root,search);
    if(found->data == search )
    {
        cout<<"Found "<<search;
    }
    else
    {
        cout<<"Not Found!";
    }

    cout<<endl;

    cout<<Min(root)<<endl;
    cout<<Max(root)<<endl;
    return 0;
}
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
bool validBST(Node* root)
{
    if(root == NULL)
    {
        return 1;
    }
    validBST(root->left);
    validBST(root->right);
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    if(root->left != NULL && root->right != NULL)
    {
        return validBST(root->left) && validBST(root->right);
    }
    return 0;
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

    cout<<validBST(root);
    return 0;
}
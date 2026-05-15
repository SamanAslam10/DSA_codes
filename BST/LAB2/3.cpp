#include <iostream>
#include <climits>

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
int IsBST(Node* root , int min , int max)
{
    int voilations = 0;
    if(root == NULL)
    {
        return 0;
    }
    if(root->data <= min || root->data >= max)
    {
        voilations ++;
    }
    voilations += IsBST(root->left,min,root->data);
    voilations += IsBST(root->right,root->data,max);

    return voilations;
}
int main()
{
    Node* root = new Node(40);
    Insert(root,20);
    Insert(root,60);

    Node* root2 = new Node(40);
    Insert(root2,20);
    Insert(root2,60);
    root2->right->left = new Node(10);

    cout<<IsBST(root2,INT_MIN,INT_MAX);
    
    return 0;
}
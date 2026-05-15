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
int leftSum(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int sum = 0;
    while(root->left != NULL)
    {
        root = root->left;
        sum += root->data;
    }

    return sum;
}
int RightSum(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int sum = 0;
    while(root->right != NULL)
    {
        root = root->right;
        sum += root->data;
    }

    return sum;
}
int Sum(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return root->data + leftSum(root) + RightSum(root);
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

    cout<<Sum(root);
    return 0;
}
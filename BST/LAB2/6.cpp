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
Node* MakeTree(int A[] , int start , int end)
{
    if(start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;

    Node* root = new Node(mid);

    root->left = MakeTree(A, start , mid-1);
    root->right = MakeTree(A,mid + 1 , end);

    return root;
}
int main()
{
    int n = 7;
    int Array[n] = {10,20,30,40,50,60,70};

    Node* root = MakeTree(Array,10,70);
    InOrder(root);
    return 0;
}
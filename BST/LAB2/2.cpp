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
bool IsBST(Node* root , int min , int max)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data <= min || root->data >= max)
    {
        return false;
    }
    return IsBST(root->left,min,root->data) && IsBST(root->right,root->data,max);
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

    if(IsBST(root2,INT_MIN,INT_MAX))
    {
        cout<<"Valid BST";
    }
    else
    {
        cout<<"NOT BST";
    }
    return 0;
}
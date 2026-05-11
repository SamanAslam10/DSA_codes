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
int CountLeftLeaf(Node* root)
{
    if(root == NULL)
    {
        return 1;
    }
    int count = 0;
    if(root->left == NULL && root->right == NULL)
    {
        count ++;
    }
    CountLeftLeaf(root->left);

    return count +1;
}
int CountRightLeaf(Node* root)
{
    if(root == NULL)
    {
        return 1;
    }
    int count = 0;
    if(root->left == NULL && root->right == NULL)
    {
        count ++;
    }
    CountRightLeaf(root->right);
    return count +1;
}
int CountLeafNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int Total = CountLeftLeaf(root) + CountRightLeaf(root);

    return Total+1;
}
int main()
{
    Node* root = NULL;
    root = new Node(45);
    Insert(root,25);
    Insert(root,65);
    Insert(root,15);
    Insert(root,35);
    Insert(root,55);
    Insert(root,75);

    cout<<CountLeafNodes(root);
    return 0;
}
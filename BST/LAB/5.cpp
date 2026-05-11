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
int CountLeft(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int count = 0;

    count += CountLeft(root->left);

    return count + 1;
}
int CountRight(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int count = 0;

    count += CountRight(root->right);

    return count + 1;
}
int CountTotalNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int Total = CountLeft(root) + CountRight(root);

    return Total + 1;
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

    cout<<CountTotalNodes(root);
    return 0;
}
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
int InternalNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root -> left == NULL && root->right == NULL)
    {
        return 0;
    }
    int internalNodes = 0;
    if(root -> left != NULL || root->right != NULL)
    {
        internalNodes += InternalNodes(root->left);
        internalNodes += InternalNodes(root->right);
    }
    return internalNodes + 1;
}
int main()
{
    Node* root = new Node(1);
    
    Node* c1 = new Node(2);
    Node* c2 = new Node(3);
    Node* c3 = new Node(4);
    Node* c4 = new Node(5);
    Node* c5 = new Node(6);
    Node* c6 = new Node(6);

    root->left = c1;
    root->right = c2;

    c1->left = c3;
    c1->right = c4;

    cout<<InternalNodes(root);
    return 0;
}
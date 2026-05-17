#include <iostream>
#include <queue>

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
int Height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = Height(root->left);
    int right = Height(root->right);

    return max(left,right) + 1;
}
int Diameter(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lheight = Height(root->left);
    int rheight = Height(root->right);

    int lDiamter = Diameter(root->left);
    int rDiameter = Diameter(root->right);

    return max(lheight + rheight + 1, max(lDiamter,rDiameter));
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

    cout<<Diameter(root);
    
    return 0;
}
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
        right = NULL;
    }
};
Node* Create(int data)
{
    Node* node = new Node(data);
    node->left = NULL;
    node->right = NULL;

    return node;
}
Node* Insert(Node* root,int data)
{
    Node* node = Create(data);
    if(root == NULL)
    {
        return node;
    }
    if(data > root->data)
    {
        root->right = Insert(root->right,data);
    }
    else
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
    cout<<root->data;
    Inorder(root->right);
}
void LevelOrder(Node* root)
{
    queue<Node*> Q;

    if(root == NULL)
    {
        return;
    }
    
    Q.push(root);

    while(!Q.empty())
    {
        Node* ptr = Q.front();
        Q.pop();

        cout<<ptr->data<<" ";

        Q.push(ptr->left);
        Q.push(ptr->right);
    }
}
int main()
{
    Node* root = new Node(10);
    Insert(root,20);
    Insert(root,0);

    LevelOrder(root);
    return 0;
}
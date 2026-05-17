#include <iostream>
#include <stack>
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
stack<Node*> s;

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
void Inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
void BFS(Node* root)
{
    queue<Node*> BFSqueue;

    if(root == NULL)
    {
        return;
    }

    BFSqueue.push(root);

    while(!BFSqueue.empty())
    {
        Node* current = BFSqueue.front();
        BFSqueue.pop();

        cout<<current->data<<" ";

        BFSqueue.push(current->left);
        BFSqueue.push(current->right);
    }
}
void Inorderx(Node* root)
{
    Node* ptr = root;
    Node* current = NULL;
    bool done = 0;
    while(!done)
    {
        if(ptr != NULL)
        {
            s.push(ptr);
            ptr = ptr->left;
        }
        else
        {
            if(!s.empty())
            {
                current = s.top();
                s.pop();
                cout<<current->data;
                ptr = current->right;
            }
            else
            {
                done = 1;
            }
        }
    }
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

    Inorder(root);
    cout<<endl;
    Preorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    BFS(root);
    cout<<endl;
    Inorderx(root);
    return 0;
}
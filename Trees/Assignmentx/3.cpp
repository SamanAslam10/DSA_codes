#include <iostream>
#include <stack>

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
stack<Node*> inStack;

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

    Node* current = root;
    Node* ptr = NULL;
    bool done = 0;

    while(!done)
    {
        if(current != NULL)
        {
            inStack.push(current);
            current = current->left;
        }

        else
        {
            if(!inStack.empty())
            {
                ptr = inStack.top();
                inStack.pop();

                cout<<ptr->data<<" ";
                current = ptr->right;
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
    
    return 0;
}
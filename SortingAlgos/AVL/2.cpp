#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value)
    {
        data = value;
        left = right = NULL;
        height = 1;
    }
};
class AVL
{
    public:

        int getHeight(Node* node)
        {
            if(node == NULL)
            {
                return 0;
            }
            return node->height;
        }

        int getBalance(Node* node)
        {
            if(node == NULL)
            {
                return 0;
            }
            return getHeight(node->left) - getHeight(node->right);
        }
        Node* RightRotate(Node* y)
        {
            Node* x = y->left;
            Node* z = x->right;

            x->right = y;
            y->left = z;

            y->height = max(getHeight(y->left),getHeight(y->right)) + 1;

            x->height = max(getHeight(x->left),getHeight(x->right)) + 1;

            return x;
        }
        Node* leftRotation(Node* x)
        {
            Node* y = x->right;
            Node* z = y->left;

            y->left = x;
            x->right = z;

            y->height = max(getHeight(y->left),getHeight(y->right)) + 1;

            x->height = max(getHeight(x->left),getHeight(x->right)) + 1;

            return y;
        }

        Node* Insert(Node* node , int key)
        {
            if(node ==NULL)
            {
                return NULL;
            }
            if(key < node->data)
            {
                node->left = Insert(node->left,key);
            }
            else if(key > node->data)
            {
                node->right = Insert(node->right,key);
            }
            else
            {
                return node;
            }

            node->height = 1 +  max(getHeight(node->left),getHeight(node->right)) + 1;

            int Balance = getBalance(node);

            if(Balance > 1 && key < node->left->data)
            {
                return RightRotate(node);
            }
            else if(Balance < -1 && key > node->right->data)
            {
                return leftRotation(node);
            }
            if(Balance > 1 && key < node->left->data)
            {
                node->left = leftRotation(node->left);
                return RightRotate(node);
            }
            else if(Balance < -1 && key > node->right->data)
            {
                node->right = RightRotate(node->right);
                return leftRotation(node);
            }

            return node;                
        }
        void InOrder(Node* node)
        {
            if(node == NULL)
            {
                return;
            }

            InOrder(node->left);
            cout<<node->data<<" ";
            InOrder(node->right);
        }
};

int main()
{
    AVL tree;
    Node* root = NULL;
    
    root = tree.Insert(root,30);
    root = tree.Insert(root, 20);

    tree.InOrder(root);
    return 0;
}
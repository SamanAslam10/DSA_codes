#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    vector<Node*> childern;

    Node(int value)
    {
        data = value;
    }
};
int Height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int height = 0;
    for(Node* child : root->childern)
    {
        int childheight = Height(child);
        if(height < childheight)
        {
            height = childheight;
        }
    }
    return height + 1;
}
int main()
{
    Node* root = new Node(10);
    Node* c1 = new Node(20);
    Node* c2 = new Node(30);

    root->childern.push_back(c1);
    root->childern.push_back(c2);

    Node* c3 = new Node(5);
    Node* c4 = new Node(6);
    c1->childern.push_back(c3);
    c1->childern.push_back(c4);

    Node* c5 = new Node(5);
    Node* c6 = new Node(6);
    c3->childern.push_back(c5);
    c5->childern.push_back(c6);

    cout<<Height(root);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
  
struct Node
{
    int data; 
    struct Node *link;
};

int main()
{
    struct Node *Head = NULL;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head -> data = 1;
    Head -> link = NULL;

    struct Node *Current = NULL;
    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 2;
    Current -> link = NULL;

    Head -> link = Current;

    Current = (struct Node *)malloc(sizeof(struct Node));
    Current ->data = 3;
    Current ->link = NULL;

    Head ->link ->link = Current;

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data ;
    struct Node *link;
};

void CountNodes(struct Node *Head);

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
    CountNodes(Head);
    return 0;
}

void CountNodes(struct Node *Head)
{
    int count = 0;
    if(Head == NULL)
    {
        printf("%s", "Linked List is empty!");
    }
    
    struct Node *next = NULL;
    next = Head;
    while(next != NULL)
    {
    next = next-> link;
    count = count + 1;
    }
    printf("%d",count);
}
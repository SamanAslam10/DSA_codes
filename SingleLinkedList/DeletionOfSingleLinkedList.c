#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
struct Node* DeleteList(struct Node *Head);
int main()
{
    struct Node *Head = NULL;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head -> data = 10;
    Head -> link = NULL;

    struct Node *Current = NULL;
    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 20;
    Current -> link = NULL;

    Head -> link = Current;

    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 30;
    Current -> link = NULL;

    Head -> link -> link= Current;

    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 70;
    Current -> link = NULL;

    Head -> link -> link -> link= Current;
    
    Head= DeleteList(Head);
    
    if(Head == NULL)
    {
        printf("%s" , "Nothing to print! list is empty.");
    }
}

struct Node* DeleteList(struct Node *Head)
{
    struct Node *ptr = Head;
    while(ptr != NULL)
    {
        ptr = ptr -> link;
        free(Head);
        Head = ptr;
    }
    return Head;
}
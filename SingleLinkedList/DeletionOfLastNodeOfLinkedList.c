#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *link;
};
struct Node* DeleteLastNode(struct Node *Head);
int main()
{
    struct Node *Head = NULL;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head -> data = 10;
    Head -> link = NULL;
    
    struct Node *Current = NULL;
    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 20;
    Current -> link = NULL;

    Head -> link = Current;

    Current =(struct Node*)malloc(sizeof(struct Node));
    Current -> data = 30;
    Current -> link = NULL;

    Head -> link -> link = Current;

    Head = DeleteLastNode(Head);

    struct Node *ptr = Head;
    while(ptr != NULL)
    {
        printf("%d , %s" , ptr->data , "  " );
        ptr = ptr ->link;
    }

    return 0;
}
struct Node* DeleteLastNode(struct Node *Head)
{
    if(Head == NULL)
    {
        printf("%s","List is already empty!");
    }
    else if(Head -> link == NULL)
    {
        free(Head);
        Head =NULL;
    }
    else
    {
        struct Node *ptr = Head;

        while(ptr->link->link != NULL)
        {
            ptr = ptr -> link;
        } 
    
        free(ptr -> link);
        ptr -> link = NULL; 
    }
    return Head;
}
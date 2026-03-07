#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
void PrintData(struct Node *Head);

int main()
{
    struct Node *Head = NULL;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head -> data = 20;
    Head -> link = NULL;

    struct Node *N1 = NULL;
    N1 = (struct Node*)malloc(sizeof(struct Node));
    N1 -> data = 30;
    N1 -> link = NULL;

    Head -> link = N1;

    struct Node *N2 = NULL;
    N2 = (struct Node*)malloc(sizeof(struct Node));
    N2 -> data = 40;
    N2 -> link = NULL;

    N1 -> link = N2;

    PrintData(Head);

    return 0;
}
void PrintData(struct Node *Head)
{
    if(Head == NULL)
    {
        printf("%s", "List is empty! Nothing to print.");
    }
    
    struct Node *temp = NULL;
    temp = Head;
    while(temp != NULL)
    {
        printf("%d,%s", temp->data , "  " );
        temp = temp ->link;
    }
}
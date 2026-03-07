#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node* AddAtBegining(struct Node *Head , int data);
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

    Head->link = Current;

    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 30;
    Current -> link = NULL;

    Head->link->link = Current;

    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 40;
    Current -> link = NULL;

    Head->link->link->link = Current;

    Head = AddAtBegining(Head , 65);

    struct Node *temp = NULL;
    temp = Head;
    while(temp != NULL)
    {
        printf("%d , %s", temp->data , "  ");
        temp = temp->link;
    }

    return 0;
}
struct Node* AddAtBegining(struct Node *Head , int data)
{
    struct Node *new = NULL; 
    new = (struct Node*)malloc(sizeof(struct Node));
    new ->data = data;
    new ->link = NULL;

    new->link = Head;
    Head = new;
    return Head;
}
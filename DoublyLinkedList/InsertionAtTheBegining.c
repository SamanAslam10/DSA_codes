#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;   
};
struct Node* AddAtBegining(struct Node *Head,int data);
int main()
{
    struct Node *Head = (struct Node*)malloc(sizeof(struct Node));
    Head -> data = 10;
    Head -> prev = NULL;
    Head -> next = NULL;

    struct Node *Current1 = (struct Node*)malloc(sizeof(struct Node));
    Current1 -> data = 20;
    Current1-> prev = Head;
    Current1 -> next = NULL;
    Head -> next = Current1;

    struct Node *Current2 = (struct Node*)malloc(sizeof(struct Node));
    Current2 -> data = 30;
    Current2 -> prev = Current1;
    Current2 -> next = NULL;

    Current1 -> next = Current2;

    Head = AddAtBegining(Head,5);

    struct Node *temp = Head;
    while(temp != NULL)
    {
        printf("%d,%s" , temp -> data ," ");
        temp = temp -> next;
    }
}
struct Node* AddAtBegining(struct Node *Head,int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = NULL;
    ptr -> prev = NULL;

    ptr -> next = Head;
    Head -> prev = ptr;

    Head = ptr;
    return Head;
}
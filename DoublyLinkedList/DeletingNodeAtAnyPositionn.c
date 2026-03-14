#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node* AddAtEnd(struct Node *Head,int data);
struct Node* AddAtBegining(struct Node *Head,int data);
struct Node* DeleteAtAnyPosition(struct Node *Head , int position);
int main()
{
    struct Node *Head; 
    Head = AddAtBegining(Head , 25);
    Head = AddAtEnd(Head , 35);
    Head = AddAtEnd(Head , 45);

    Head = DeleteAtAnyPosition(Head,2);
    struct Node *temp = Head;
    while(temp != NULL)
    {
        printf("%d,%s" , temp -> data , "  ");
        temp = temp -> next;
    }

    return 0;
}
struct Node* AddAtBegining(struct Node *Head,int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = NULL;
    ptr -> prev = NULL;

    Head = ptr;
    return Head;
}
struct Node* AddAtEnd(struct Node *Head,int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = NULL;
    ptr -> prev = NULL;

    struct Node *temp = Head;
    while(temp->next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = ptr;
    ptr -> prev = temp;

    return Head;
}
struct Node* DeleteAtAnyPosition(struct Node *Head , int position)
{
    struct Node *ptr = Head;

    while(position != 1)
    {
        ptr = ptr -> next;
        position --;
    }

    struct Node *temp = ptr -> prev;
    temp -> next = ptr -> next;
    ptr -> next -> prev = temp;

    free(ptr);
    ptr = NULL;
    return Head;
}
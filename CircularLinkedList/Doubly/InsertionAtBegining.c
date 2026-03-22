#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node* Create(int arr[],int n)
{
    struct Node *ptr , *temp , *head;
    head = (struct Node*)malloc(sizeof(struct Node));
    head -> data = arr[0];
    head -> prev = head;
    head -> next = head;

    temp = head;

    for(int i = 1; i < n ; i ++)
    {
        ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr -> data = arr[i];
        ptr -> next = head;
        ptr -> prev = temp;

        temp -> next = ptr;
        temp = ptr;
    }
    return temp;
}
void Display(struct Node *tail)
{
    struct Node *ptr = tail->next;
    do
    {
        printf("%d,%s" , ptr -> data , " ");
        ptr = ptr -> next;
    }
    while(ptr->prev != tail);
}
struct Node* InsertAtBegining(struct Node* tail, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node*));
    ptr -> data = data;
    ptr -> next = ptr;
    ptr -> prev = ptr; 

    ptr -> prev = tail;
    ptr -> next = tail -> next;
    tail -> next = ptr;

    return tail;
}
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = 6;

    struct Node* tail = Create(arr,n);

    tail = InsertAtBegining(tail,0);
    Display(tail);
    return 0;
}
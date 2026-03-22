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
    struct Node *ptr = tail;
    do
    {
        printf("%d,%s" , ptr -> data , " ");
        ptr = ptr -> next;
    }
    while(ptr != tail);
}
struct Node* InsertionInBetween(struct Node* tail ,int data , int position)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = ptr;
    ptr -> prev = ptr;

    struct Node *temp = tail;
    while(position > 1)
    {
        temp = temp -> next;
        position --;
    }
    ptr -> next = temp -> next;
    temp -> next = ptr;
    ptr -> prev = temp;

    return tail;
}
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = 6;

    struct Node* tail = Create(arr,n);
    tail = InsertionInBetween(tail,99,3);
    Display(tail);
    return 0;
}

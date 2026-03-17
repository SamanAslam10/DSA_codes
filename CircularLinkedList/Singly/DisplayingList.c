#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node* Create(int arr[] , int n);
int main()
{
    int n = 5;
    int array[] = {1,2,3,4,5};

    struct Node *Head = Create(array , n);
}
struct Node* Create(int arr[] , int n)
{
    struct Node *ptr , *last;
    struct Node *Head = (struct Node*)malloc(sizeof(struct Node));
    Head -> data = arr[0];
    Head -> next = Head;
    last = Head;

    for(int i = 1; i < n ; i ++)
    {
        ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr -> data = arr[i];
        ptr -> next = last ->next;
        last -> next = ptr;
        last = ptr;
    }

    return Head;
}
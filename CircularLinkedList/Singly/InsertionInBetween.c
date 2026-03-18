#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node* Create(int arr[],int n)
{
    struct Node *head,*tail,*ptr;
    head = (struct Node*)malloc(sizeof(struct Node));
    head-> data = arr[0];
    head-> next = head;

    tail = head;

    for(int i = 1; i <n ; i ++)
    {
        ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr -> data = arr[i];
        ptr -> next = head;
        tail -> next = ptr;
        tail = ptr;
    }
    return tail;
}
void Display(struct Node *tail)
{
    struct Node *ptr = tail;
    do
    {
        printf("%d,%s" , ptr->next-> data ," ");
        ptr = ptr -> next;
    }while(ptr!= tail);
}
struct Node* InsertInBetween(struct Node *tail , int data , int position)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = NULL;

    struct Node *temp = tail -> next;
    while(position != 1)
    {
        temp = temp -> next;
        position --;
    }
    ptr -> next = temp -> next;
    temp -> next = ptr;

    return tail;
}
int main()
{
    int array[] = {10,20,30,40,50};
    int n = 5;

    struct Node *tail = Create(array , n);
    Display(tail);
    printf("\n");
    tail = InsertInBetween(tail , 55 , 4);
    Display(tail);
}
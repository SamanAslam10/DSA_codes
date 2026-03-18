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
struct Node *DeleteLastNode(struct Node *tail)
{
    struct Node *temp = tail -> next;

    while(temp -> next != tail)
    {
        temp = temp -> next;
    }
    struct Node *freenode = temp -> next;
    tail = tail -> next;
    temp -> next = tail;


    free(freenode);
    freenode = NULL;

    return tail;

}
int main()
{
    int array[] = {10,20,30,40,50};
    int n = 5;

    struct Node *tail = Create(array , n);
    Display(tail);
    printf("\n");
    tail = DeleteLastNode(tail);
    Display(tail);
}
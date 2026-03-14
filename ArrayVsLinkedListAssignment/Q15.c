#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* merge(struct Node* a, struct Node* b)
{
    if(a==NULL) return b;
    if(b==NULL) return a;

    struct Node* result=NULL;

    if(a->data <= b->data)
    {
        result=a;
        result->next=merge(a->next,b);
    }
    else
    {
        result=b;
        result->next=merge(a,b->next);
    }

    return result;
}

void printList(struct Node* head)
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // List 1: 1 -> 3 -> 5
    struct Node *a1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *a2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *a3 = (struct Node*)malloc(sizeof(struct Node));

    a1->data = 1; a1->next = a2;
    a2->data = 3; a2->next = a3;
    a3->data = 5; a3->next = NULL;

    // List 2: 2 -> 4 -> 6
    struct Node *b1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *b2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *b3 = (struct Node*)malloc(sizeof(struct Node));

    b1->data = 2; b1->next = b2;
    b2->data = 4; b2->next = b3;
    b3->data = 6; b3->next = NULL;

    printf("List A: ");
    printList(a1);
    printf("List B: ");
    printList(b1);

    struct Node* merged = merge(a1, b1);

    printf("Merged List: ");
    printList(merged);

    return 0;
}
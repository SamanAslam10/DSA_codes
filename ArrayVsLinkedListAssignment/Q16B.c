#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void removeDuplicates(struct Node* head)
{
    struct Node* temp=head;

    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            struct Node* dup=temp->next;
            temp->next=temp->next->next;
            free(dup);
        }
        else
            temp=temp->next;
    }
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // Sorted list: 1 -> 2 -> 2 -> 3 -> 3 -> 4 -> NULL
    struct Node *n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n5 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n6 = (struct Node*)malloc(sizeof(struct Node));

    n1->data=1; n1->next=n2;
    n2->data=2; n2->next=n3;
    n3->data=2; n3->next=n4;
    n4->data=3; n4->next=n5;
    n5->data=3; n5->next=n6;
    n6->data=4; n6->next=NULL;

    struct Node* head = n1;

    printf("Original List: ");
    printList(head);

    removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
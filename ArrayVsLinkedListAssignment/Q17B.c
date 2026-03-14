#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* rotateList(struct Node* head,int k)
{
    if(head==NULL) return head;

    struct Node* temp=head;
    int count=1;

    while(count<k && temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    if(temp==NULL) return head;

    struct Node* kthNode=temp;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=head;

    head=kthNode->next;

    kthNode->next=NULL;

    return head;
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
    struct Node *n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n5 = (struct Node*)malloc(sizeof(struct Node));

    n1->data=1; n1->next=n2;
    n2->data=2; n2->next=n3;
    n3->data=3; n3->next=n4;
    n4->data=4; n4->next=n5;
    n5->data=5; n5->next=NULL;

    struct Node* head = n1;

    printf("Original List: ");
    printList(head);

    int k;
    printf("Enter k for rotation: ");
    scanf("%d",&k);

    head = rotateList(head, k);

    printf("List after rotation: ");
    printList(head);

    return 0;
}
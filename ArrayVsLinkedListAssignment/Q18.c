#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* nthFromEnd(struct Node* head,int n)
{
    struct Node* first=head;
    struct Node* second=head;

    for(int i=0;i<n;i++)
        first=first->next;

    while(first!=NULL)
    {
        first=first->next;
        second=second->next;
    }

    return second;
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

    n1->data=10; n1->next=n2;
    n2->data=20; n2->next=n3;
    n3->data=30; n3->next=n4;
    n4->data=40; n4->next=n5;
    n5->data=50; n5->next=NULL;

    struct Node* head = n1;

    printf("Linked List: ");
    printList(head);

    int n;
    printf("Enter n (nth node from end): ");
    scanf("%d", &n);

    struct Node* node = nthFromEnd(head, n);

    if(node != NULL)
        printf("%dth node from the end is: %d\n", n, node->data);
    else
        printf("List is shorter than %d nodes.\n", n);

    return 0;
}
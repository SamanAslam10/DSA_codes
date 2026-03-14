#include <stdio.h>

#define MAX 100

int arr[MAX];
int size = 0;

void traverse()
{
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void insert_begin(int val)
{
    for(int i=size;i>0;i--)
        arr[i]=arr[i-1];

    arr[0]=val;
    size++;
}
void insert_end(int val)
{
    arr[size]=val;
    size++;
}
void insert_pos(int pos,int val)
{
    for(int i=size;i>pos;i--)
        arr[i]=arr[i-1];

    arr[pos]=val;
    size++;
}
void delete_begin()
{
    for(int i=0;i<size-1;i++)
        arr[i]=arr[i+1];

    size--;
}
void delete_end()
{
    size--;
}
void delete_pos(int pos)
{
    for(int i=pos;i<size-1;i++)
        arr[i]=arr[i+1];

    size--;
}
void search(int key)
{
    int found=0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            printf("Element found at index %d\n",i);
            found=1;
            break;
        }
    }

    if(!found)
        printf("Element not found\n");
}
int main()
{
    insert_end(10);
    insert_end(20);
    insert_end(30);

    traverse();

    insert_begin(5);
    traverse();

    insert_pos(2,15);
    traverse();

    delete_begin();
    traverse();

    delete_end();
    traverse();

    search(20);

    return 0;
}
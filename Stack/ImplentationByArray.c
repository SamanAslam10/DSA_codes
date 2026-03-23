#include <stdio.h>
#include <stdlib.h>


int n = 5;
int array[5];
int Top = -1;
void push(int data)
{
    Top = Top + 1;
    array[Top] = data;
}
void pop()
{
    Top = Top - 1;
}
int empty()
{
    if(Top == -1)
    {
        return 1;
    }
    return 0;
}
int top()
{
    return array[Top];
}
int StackOverFlow()
{
    if (Top >= n)
    {
        return 1;
    }
    return 0;
}
int main()
{
    push(5);
    push(3);
    pop();
    printf("%d" , top());
    return 0;
}
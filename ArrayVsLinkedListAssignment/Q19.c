#include <iostream>
using namespace std;

class DynamicArray
{
    int *arr;
    int size;
    int capacity;

public:

    DynamicArray()
    {
        capacity=2;
        size=0;
        arr=new int[capacity];
    }

    void resize()
    {
        capacity*=2;
        int *newArr=new int[capacity];
        for(int i=0;i<size;i++)
            newArr[i]=arr[i];
        delete[] arr;
        arr=newArr;
    }

    void append(int val)
    {
        if(size==capacity)
            resize();
        arr[size++]=val;
    }

    void insert(int pos,int val)
    {
        if(size==capacity)
            resize();
        for(int i=size;i>pos;i--)
            arr[i]=arr[i-1];
        arr[pos]=val;
        size++;
    }

    void remove(int pos)
    {
        for(int i=pos;i<size-1;i++)
            arr[i]=arr[i+1];
        size--;
    }

    int get(int pos)
    {
        return arr[pos];
    }

    void set(int pos,int val)
    {
        arr[pos]=val;
    }

    void print()
    {
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    DynamicArray arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);
    arr.append(40);

    cout<<"Array after appends: ";
    arr.print();

    arr.insert(2, 25);
    cout<<"Array after inserting 25 at position 2: ";
    arr.print();

    arr.remove(1);
    cout<<"Array after removing element at position 1: ";
    arr.print();

    cout<<"Element at position 2: "<<arr.get(2)<<endl;

    arr.set(2, 35);
    cout<<"Array after setting position 2 to 35: ";
    arr.print();

    return 0;
}
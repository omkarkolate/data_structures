#include<iostream>
using namespace std;

int siz;
int front = -1;
int rear = -1;

bool isEmpty()
{
    if((front == -1 && rear == -1) || (front > rear))
        return true;
    return false;
}

bool isFull()
{
    if(rear == siz-1)
        return true;
    return false;

}

void enQueue(int arr[])
{
    if (!isFull())
    {   
        if(front == -1 && rear == -1)
            front++;
        cout<<"Enter data: ";
        cin>>arr[++rear];
    }
    else
    {
        cout<<"Queue is Full!!\nMemeory full\n";
    }
}

void deQueue(int arr[])
{
    if(!isEmpty())
    {
        cout<<arr[front++]<<"\n";
    }
    else
    {
        cout<<"Queue is Empty!!!\n";
    }
    
}

void frontOfQueue(int arr[])
{
    if(!isEmpty())
        cout<<arr[front]<<"\n";
    else
    {
        cout<<"Queue is Empty!!!\n";   
    }
    
}

void menu()
{
    cout<<"1. Enqueue\n";
    cout<<"2. Dequeue\n";
    cout<<"3. Front\n";
    cout<<"4. Exit\n";
}

int main()
{
    cout<<"Queue using Array\n";
    cout<<"Enter size of the queue: ";
    cin>>siz;
    int arr[siz];

    while (true)
    {
        menu();
        int choise;
        cout<<"Enter the option: ";
        cin>>choise;

        switch (choise)
        {
            case 1:
                enQueue(arr);
                break;
            
            case 2:
                deQueue(arr);
                break;

            case 3:
                frontOfQueue(arr);
                break;
            case 4:
                exit(0);
            default:
                cout<<"You have entered the wrong option\n";
                break;
            }
    }
    return 0;
}
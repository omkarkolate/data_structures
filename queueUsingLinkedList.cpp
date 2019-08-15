#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *front = NULL;
node *rear = NULL;

node *createNode()
{
    node *newNode = new node();
    cout<<"Enter data: ";
    cin>>newNode->data;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty()
{
    if (front == NULL && rear == NULL)
        return true;
    
    return false;
}

void enQueue()
{
    if (isEmpty())
    {
        rear = createNode();
        front = rear;
    }
    else
    {
        rear->next = createNode();
        rear = rear->next;
    }
        
}

void deQueue()
{
    if(!isEmpty())
    {
        cout<<front->data<<"\n";
        node *temp = front;
        front = front->next;
        delete temp;
        
        if(front == NULL)
            rear = NULL;
    }
    else
        cout<<"Queue is empty!!\n";
    
}

void frontOfQueue()
{
    if(!isEmpty())
        cout<<front->data<<"\n";
    else
        cout<<"Queue is empty!!\n";
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
    cout<<"Queue using linked list\n";

    while (true)
    {
        menu();
        int choise;
        cout<<"Enter the option: ";
        cin>>choise;

        switch (choise)
        {
            case 1:
                enQueue();
                break;
            
            case 2:
                deQueue();
                break;

            case 3:
                frontOfQueue();
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
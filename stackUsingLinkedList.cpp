#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *top = NULL; 

node* createNode()
{
    node *newNode = new node();
    cout<<"Enter data: ";
    cin>>newNode->data;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty()
{
    if (top == NULL)
        return true;
    return false;    
}

void push()
{
    if(isEmpty())
        top = createNode();
    else
    {
        node *newNode = createNode();
        newNode->next = top;
        top = newNode;
    }
}

void pop()
{
    if (!isEmpty())
    {
        cout<<top->data<<"\n";
        node *temp = top;
        top = top->next;
        delete temp;
    }
    else
        cout<<"Stack is Underflow!!\n";
}

void topOfStack()
{
    if(!isEmpty())
        cout<<top->data<<"\n";
    else
        cout<<"Stack is Underflow!!\n";
}

void menu()
{
    cout<<"Menu\n";
    cout<<"1.Push\n";
    cout<<"2.Pop\n";
    cout<<"3.Top\n";
    cout<<"4.Exit\n";
}

int main()
{
    cout<<"Stack using Array\n";

    while (true)
    {
        int choise;
        menu();
        cout<<"Enter the option: ";
        cin>>choise;

        switch (choise)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                topOfStack();
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
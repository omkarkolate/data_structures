#include<iostream>
using namespace std;

int siz;
int top=-1;

bool isEmpty()
{
    if (top == -1)
        return true;
    return false;    
}

bool isFull()
{
    if(top >= siz-1)
        return true;
    return false;
}

void push(int arr[])
{
    if (!isFull())
    {
        cout<<"Enter data: ";
        cin>>arr[++top];
    }
    else
        cout<<"Stack is Overflow!!\n";
}

void pop(int arr[])
{
    if (!isEmpty())
        cout<<arr[top--]<<"\n";
    else
        cout<<"Stack is Underflow!!\n";
}

void topOfStack(int arr[])
{
    if(!isEmpty())
        cout<<arr[top]<<"\n";
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
    cout<<"Enter the size of the array: ";
    cin>>siz;
    int arr[siz];
    while (true)
    {
        int choise;
        menu();
        cout<<"Enter the option: ";
        cin>>choise;

        switch (choise)
        {
            case 1:
                push(arr);
                break;
            case 2:
                pop(arr);
                break;
            case 3:
                topOfStack(arr);
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
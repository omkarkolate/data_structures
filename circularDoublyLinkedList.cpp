#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

node *head = NULL; 
node *tail = NULL;
int length = 0;

node* createNode()
{
    node *newNode = new node();
    cout<<"Enter data: ";
    cin>>newNode->data;
    newNode->prev = NULL;
    newNode->next = NULL;
    length++;
    return newNode;
}

void insertNodeAtEnd(int pos)
{
    node *temp = createNode();

    if(head == NULL)
    {
        head = temp;
        head->next = head;
        head->prev = head;
    }

    else
    {
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev =temp;
    }

    if(pos == 0) head = temp;
    
}

void insertNodeAtPosition()
{
    int pos;
    cout<<"Enter the position: ";
    cin>>pos;
    if(pos > length)
        insertNodeAtEnd(1);
    else if(pos == 1)
        insertNodeAtEnd(0);
    else
    {
        node *temp = head;
        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }

        node *newNode = createNode();
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode->next;
        temp->prev = newNode;     
    }
    
}

void deleteNode()
{
    int pos;
    cout<<"Enter Position: ";
    cin>>pos;
    if(head == NULL)
    {
        cout<<"List is empty!!\n";
        return;
    }
        
    else if(pos == 1)
    {
        node *temp = head;
        if(head->next == head)
        {
            head = NULL;
            delete temp;
        }
        else
        {
            head = head->next;
            head->prev = temp->prev;
            temp->prev->next = head;
            delete temp;
        }
    }
    else
    {
        node *temp = head;

        for (int i = 1; i < pos; i++)
            temp = temp->next;
        
        node *prevNode = temp->prev;
        node *nextNode = temp->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete temp;
    }
    length--;
}

void reverseList()
{
    head = head->prev;
    node *current = head;
    node *prevNode = current->prev;
    do
    {
        current->prev = current->next;
        current->next = prevNode;
        current = prevNode;
        prevNode = prevNode->prev;
    } while (current != head);
    
}

void recursiveReverseList(node *prevNode)
{
    if(prevNode == head)
    {
        return;
    }

    recursiveReverseList(prevNode->next);

    node *nextNode = prevNode->next;
    nextNode->prev = nextNode->next;
    nextNode->next = prevNode;
    prevNode->prev = nextNode;
    prevNode->next = head;
}

void reversePrint()
{
    node *temp = head->prev;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    } while (temp != head->prev);
    cout<<"\n";
}

void recursiveReversePrint(node *temp)
{
    if(temp == head)
        return;
    cout<<temp->data<<" ";
    recursiveReversePrint(temp->prev);
}

void printList()
{
    if(head == NULL)
        cout<<"List is empty!!\n";
    else
    {
        node *temp = head;

        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        } while (temp != head);
        cout<<"\nLength: "<<length<<"\n";
    }
}

void menu()
{
    cout<<"--Menu--"<<endl;
    cout<<"1. Insert node at the end."<<endl;
    cout<<"2. Insert node at the start."<<endl;
    cout<<"3. Insert node at position."<<endl;
    cout<<"4. Delete node."<<endl;
    cout<<"5. Print list."<<endl;
    cout<<"6. Reverse(Iterative) the list."<<endl;
    cout<<"7. Reverse(Recursive) the list."<<endl;
    cout<<"8. Reverse(Iterative) print."<<endl;
    cout<<"9. Reverse(Recursive) print."<<endl;
    cout<<"10. Exit."<<endl;
}

int main()
{
    cout<<"Circular Doubly Linked List\n";

    while(true)
    {
        int choise;
        menu();
        cout<<"Enter the Option Number: ";
        cin>>choise;
        switch (choise)
        {
        case 1:
            int n;
            cout<<"How many nodes to be insert: ";
            cin>>n;
            for(int i=0; i<n; i++)
                insertNodeAtEnd(1);
            break;
        case 2:
            insertNodeAtEnd(0);
            break;
        case 3:
            insertNodeAtPosition();
            break;
        case 4: 
            deleteNode();
            break;
        case 5:
            printList();
            break;
        case 6:
            reverseList();
            break;
        case 7:
            recursiveReverseList(head->next);
            head = head->next;
            break;
        case 8:
            reversePrint();
            break;
        case 9:
            recursiveReversePrint(head->prev);
            cout<<head->data<<"\n";
            break;
        case 10:
            exit(0);
            break;
        default:
            cout<<"You have entered wrong choice."<<endl;
            break;
        }
    }

    return 0;
}

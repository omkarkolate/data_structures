#include<iostream>
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
    int data;
    cout<<"Enter data: ";
    node *newNode = new node();
    cin>>newNode->data;
    newNode->prev = NULL;
    newNode->next = NULL;
    length++;
    return newNode;
}

void insertNodeAtEnd()
{
    if(head == NULL)
    {
        head = createNode();
        tail = head;
    }
    else
    {
        node *temp = createNode();
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}

void insertNodeAtStart()
{
    if(head == NULL)
    {
        head = createNode();
        tail = head;
    }
    else
    {
        node *temp = createNode();
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
       
}

void insertNodeAtPosition()
{
    int pos;
    cout<<"Enter the position: ";
    cin>>pos;
    if(pos > length)
        insertNodeAtEnd();
    else if(pos == 1)
        insertNodeAtStart();
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
    cout<<"Enter node position to delete: ";
    cin>>pos;
    node *current = head;
    if(pos == 1)
    {
        head = current->next;
        head->prev = NULL;
        delete current;
    }
    else if (pos == length)
    {
        node *prevNode = tail->prev;
        prevNode->next = NULL;
        delete tail;
        tail = prevNode;
    }
    
    else
    {
        for(int i=1; i<pos; i++)
        {
            current=current->next;
        }

        node *preNode = current->prev;
        node *nextNode = current->next;
        preNode->next = nextNode;
        nextNode->prev = preNode;
        delete current;
    }
    length--;
}

void printList()
{
    if(head == NULL)
        cout<<"List is empty!!"<<endl;
    else
    {
        node *temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
           cout<<"\nLength of the list: "<<length<<endl;         
    }
}

void reverseList()
{
    node *current = head;

    while(current != NULL)
    {
        node *prevNode = current->prev;
        current->prev = current->next;
        current->next = prevNode;
        current = current->prev;
    }
    current = tail;
    tail = head;
    head = current; 
}

void recursiveReverseList(node *prevNode)
{
    if (prevNode->next == NULL)
    {
        head = prevNode;
        return;
    }
    
    recursiveReverseList(prevNode->next);
    node *nextNode = prevNode->next;;
    nextNode->prev = nextNode->next;
    nextNode->next = prevNode;
    prevNode->prev = nextNode;
}

void reversePrint()
{
    node *temp = tail;

    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

void recursiveReversePrint(node *temp)
{
    if(temp == NULL)
        return;
    
    recursiveReversePrint(temp->next);
    cout<<temp->data<<" ";
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
    cout<<"Doubly Linked List"<<endl;

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
                insertNodeAtEnd();
            break;
        case 2:
            insertNodeAtStart();
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
            tail = head;
            recursiveReverseList(head);
            tail->next = NULL;
            break;
        case 8:
            reversePrint();
            break;
        case 9:
            recursiveReversePrint(head);
            cout<<endl;
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
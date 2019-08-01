#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;
node *tail = NULL;
int length = 0;

node* createNode()
{
    node *newNode = new node();
    cout<<"Enter Data: ";
    cin>>newNode->data;
    newNode->next=NULL;
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
        tail->next=createNode();
        tail = tail->next;
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
        node *temp=createNode();
        temp->next = head;
        head = temp;
    }
    
}

void insertNodeAtPosition()
{
    int pos;
    cout<<"Enter the Position: ";
    cin>>pos;
    if(pos > length)
        insertNodeAtEnd();
    else if(pos == 1)
        insertNodeAtStart();
    else
    {
        node *temp=head;
        for(int i=1; i<pos-1; i++)
            temp=temp->next;

        node* newNOde = createNode();
        newNOde->next = temp->next;
        temp->next = newNOde;
    }
    
}

void deleteNode()
{
    int pos;
    cout<<"Enter the Position to delete: ";
    cin>>pos;
    node *temp = head;
    if(pos == 1)
    {
        head = temp->next;
        delete temp;
    }
    else
    {
        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        if(pos == length)
            tail = temp;
        node *temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
    }
    length--;
}

void reverseList()
{
    node *current = head->next;
    node *prevNode = head;
    node *nextNode = current;
    while(nextNode != NULL)
    {
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    }
    tail = head;
    head = prevNode;
    tail->next = NULL;
}

void recursiveReverseList(node *prevNode)
{
    if(prevNode->next == NULL)
    {
        head = prevNode;
        return;
    }
    recursiveReverseList(prevNode->next);
    node *nextNode = prevNode->next;
    nextNode->next = prevNode;
    prevNode->next = NULL;
}

void recursiveReversePrint(node *temp)
{
    if(temp == NULL)
        return;
    recursiveReversePrint(temp->next);
    cout<<temp->data<<" ";
}

void printList()
{
    node *temp = head;
    if(temp == NULL)
        cout<<"List is Empty!\n";
    else
    {
        while (temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\nLength of the list: "<<length<<endl;
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
    cout<<"8. Reverse(Recursive) print."<<endl;
    cout<<"9. Exit."<<endl;
}

int main()
{
    cout<<"Singly Linked List\n";
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
            break;
        case 8:
            recursiveReversePrint(head);
            cout<<endl;
            break;
        case 9:
            exit(0);
            break;
        default:
            cout<<"You have entered wrong choice."<<endl;
            break;
        }
    }
    return 0;
}
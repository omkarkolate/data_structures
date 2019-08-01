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
    int data;
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
        head->next = head;
        tail = head;
    }

    else
    {
        node *temp = createNode();
        tail->next = temp;
        temp->next = head;
        tail = temp;
    }
}

void insertNodeAtStart()
{
    if(head == NULL)
    {
        head = createNode();
        head->next = head;
        tail = head;
    }
    else
    {
        node *temp = createNode();
        temp->next = head;
        tail->next = temp;
        head = temp;    
    }
    
}

void insertNodeAtPosition()
{
    cout<<"Enter Position: ";
    int pos;
    cin>>pos;
    if(pos == 1)
        insertNodeAtStart();
    else if (pos > length)
        insertNodeAtEnd();
    
    else
    {
        node *temp = head;
        for(int i=1; i<pos-1; i++)
            temp = temp->next;

        node *newNode = createNode();
        newNode->next = temp->next;
        temp->next = newNode;
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
        tail->next = head;
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
    node *current = head;
    node *prevNode = tail;
    node *nextNode = current->next;

    do
    {
        current->next = prevNode;
        prevNode = current;
        current  = nextNode;
        nextNode = nextNode->next;
    } while (current != head);

    head = tail;
    tail = current;
}

void recursiveReverseList(node  *prevNode)
{
    if(prevNode == head)
        return;
    
    recursiveReverseList(prevNode->next);

    node *nextNode = prevNode->next;
    nextNode->next = prevNode;
    prevNode->next = head;
}

void recursiveReversePrint(node *temp)
{
    if(temp == head)
        return;
    recursiveReversePrint(temp->next);
    cout<<temp->data<<" ";
}

void printList()
{
    if(head == NULL)
        cout<<"List is empty!!"<<endl;
    
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
    cout<<"8. Reverse(Recursive) print."<<endl;
    cout<<"9. Exit."<<endl;
}

int main()
{
    cout<<"Circular Singly Linked List\n";

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
            recursiveReverseList(head->next);
            tail = head;
            head = tail->next;
            break;
        case 8:
            recursiveReversePrint(head->next);
            cout<<" "<<head->data<<"\n";
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
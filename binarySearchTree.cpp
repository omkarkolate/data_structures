#include<iostream>
#include<stack>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *root = NULL; 

node* createNode()
{
    node *newNode = new node();
    cout<<"Enter data: ";
    cin>>newNode->data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode()
{
    node *newNode = createNode();
    
    if(root == NULL)
        root = newNode;
    else
    {   
       node *current = root;
       node *prev;
       while(current != NULL)
       {
            prev = current;
            if(newNode->data <= current->data)
                current = current->left;
            else
                current = current->right;
       }
       
        if(newNode->data <= prev->data)
            prev->left = newNode;
        else
            prev->right = newNode;
    }
    
}

void preOrder()
{
    node *current = root;
    stack <node*> stk;
    do
    {
        while (current != NULL)
        {
            stk.push(current);
            cout<<current->data<<" ";
            current = current->left;
        }
        
        if (!stk.empty())
        {
            current = stk.top();
            stk.pop();
            current = current->right;
        }
        
    } while (!stk.empty() || current != NULL);
    cout<<"\n";
}

void inorder()
{
    node *current = root;
    stack <node*> stk;
    do
    {
        while (current != NULL)
        {
            stk.push(current);
            current = current->left;
        }
        
        if(!stk.empty())
        {
            current = stk.top();
            cout<<current->data<<" ";
            stk.pop();
            current = current->right;
        }

    } while (!stk.empty() || current != NULL);
    cout<<"\n";
}

void postOrder()
{
    node *current = root;
    stack <node*> stk;
    do
    {
        while (current != NULL)
        {
            stk.push(current);
            current = current->left;
        }
        
        if (!stk.empty())
        {
            current = stk.top();
            if(current->right == NULL)
            {
                cout<<current->data<<" ";
                stk.pop();

                while(!stk.empty() && current == stk.top()->right)
                {
                    current = stk.top();
                    cout<<current->data<<" ";
                    stk.pop();
                }
            
                if (!stk.empty())
                {
                    current = stk.top();
                    current = current->right;
                }
                else
                    current = NULL;
            }
            else
                current = current->right;
        }
    } while (!stk.empty() || current != NULL);
    cout<<"\n";
}

void menu()
{
    cout<<"1.Insert Node\n";
    cout<<"2.Preorder Traversal\n";
    cout<<"3.Inorder Traversal\n";
    cout<<"4.Postorder Traversal\n";
    cout<<"5.Exit\n";
}

int main()
{
    cout<<"Binary Search Tree\n";

    while (true)
    {
        int choise;
        menu();
        cout<<"Enter the option: ";
        cin>>choise;

        switch (choise)
        {
        case 1:
            insertNode();
            break;
        
        case 2:
            preOrder();
            break;
        case 3:
            inorder();
            break;
        case 4:
            postOrder();
            break;
        case 5:
            exit(0);

        default:
            cout<<"You have entered wrong option\n";
            break;
        }
    }
    return 0;
}
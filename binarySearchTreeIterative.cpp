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

void search()
{
    cout<<"Enter data to search: ";
    int key;
    cin>>key;

    node *current = root;
    bool flag = false;
    while (current != NULL)
    {
        if(current->data == key)
        {
            flag = true;
            break;
        }
        else if(key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (flag == true)
        cout<<"Data Found :)\n";
    else
        cout<<"Not Found :(\n";
    
}

void preOrder()
{
    if (root == NULL)
    {
        cout<<"Tree is empty!!\n";
        return;
    }
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
    if (root == NULL)
    {
        cout<<"Tree is empty\n";
        return;
    }
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
    if (root == NULL)
    {
        cout<<"Tree is empty\n";
        return;
    }
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

void deleteNode(node *current,int key)
{
    if (current == NULL)
    {
        cout<<"Tree is empty\n";
        return;
    }
    node *prev;
    while (current != NULL)
    {
        if(current->data == key)
            break;
        else if (key < current->data)
        {
            prev = current;
            current = current->left;
        }
        else
        {
            prev = current;
            current = current->right;
        }
    }
    if(current == NULL)
    {
        cout<<"Data Not Found!!\n";
        return;
    }
    else if (current == root)
    {
        //Case 1: Root has No child
        if ((current->left == NULL) && (current->right == NULL))
        {
            root = NULL;
            delete current;
            cout<<"Node is deleted Successfully. <;)\n";
            return;
        }
        //Case 2: Has One child
        //Case 2.1: Has Right child
        else if (current->left == NULL)
        {
            root = root->right;
            delete current;
            cout<<"Node is deleted Successfully. <;)\n";
            return;
        }
        //Case 2.2: Has Left child
        else if(current->right == NULL)
        {
            root = root->left;
            delete current;
            cout<<"Node is deleted Successfully. <;)\n";
            return;
        }    
    }
    
    //Case 1: Has No child
    if ((current->left == NULL) && (current->right == NULL))
    {
        if (current->data <= prev->data)
        {
            prev->left = NULL;
            delete current;
        }
        else
        {
            prev->right = NULL;
            delete current;
        }
        cout<<"Node is deleted Successfully. <;)\n"; 
    }
    //Case 2: Has One child
    //Case 2.1: Has Right child
    else if (current->left == NULL)
    {
        node *rightNode = current->right;
        if(rightNode->data <= prev->data)
            prev->left = rightNode;
        else
            prev->right = rightNode;
        delete current;
        cout<<"Node is deleted Successfully. <;)\n";
    }
    //Case 2.2: Has Left child
    else if (current->right == NULL)
    {
        node *leftNode = current->left;
        if(leftNode->data <= prev->data)
            prev->left = leftNode;
        else
            prev->right = leftNode;
        delete current;
        cout<<"Node is deleted Successfully. <;)\n";
    }    
    else
    {
        node *minNode = current->right;
        while (minNode->left != NULL)
            minNode = minNode->left;
        int min = minNode->data;
        if(current->data == minNode->data)
            deleteNode(current->right,minNode->data);
        else
            deleteNode(current,minNode->data);
        current->data = min;
    }
    return;   
}
void menu()
{
    cout<<"1.Insert Node\n";
    cout<<"2.Search data\n";
    cout<<"3.Preorder Traversal\n";
    cout<<"4.Inorder Traversal\n";
    cout<<"5.Postorder Traversal\n";
    cout<<"6.Delete Node\n";
    cout<<"7.Exit\n";
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
                search();
                break;
            case 3:
                preOrder();
                break;
            case 4:
                inorder();
                break;
            case 5:
                postOrder();
                break;
            case 6:
                int key;
                cout<<"Enter data to be delete: ";
                cin>>key;
                deleteNode(root,key);
                break;
            case 7:
                exit(0);
            default:
                cout<<"You have entered wrong option\n";
                break;
        }
    }
    return 0;
}
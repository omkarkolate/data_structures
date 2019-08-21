#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *root = NULL;
bool flag;

node* createNode(int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insertNode(node *current, int data)
{
    if(current == NULL)
        current = createNode(data);
    else if(data <= current->data)
        current->left = insertNode(current->left,data);
    else
        current->right = insertNode(current->right,data);
    return current;
}

bool search(node *current, int data)
{
    if (current == NULL)
        return false;
    else if (current->data == data)
        return true;
    else if (data < current->data)
        search(current->left,data);
    else if (data > current->data)
        search(current->right,data);
}

void preOrder(node *current)
{
    if(current == NULL)
        return;
    cout<<current->data<<" ";
    preOrder(current->left);
    preOrder(current->right);
}

void inorder(node *current)
{
    if(current == NULL)
        return;
    inorder(current->left);
    cout<<current->data<<" ";
    inorder(current->right);
}

void postOrder(node *current)
{
    if(current == NULL)
        return;
    postOrder(current->left);
    postOrder(current->right);
    cout<<current->data<<" ";
}

//Fuction to find minimum value from right subtree
node* minNode(node *current)
{
    while (current->left != NULL)
        current = current->left;
    return current;    
}

node* deleteNode(node *current, int data)
{
    if(current == NULL)
        return current;
    else if(data < current->data)
        current->left = deleteNode(current->left,data);
    else if(data > current->data)
        current->right = deleteNode(current->right,data);
    else
    {
        //Data is Found
        flag = true;
        //Case 1:Has No child
        if (current->left == NULL && current->right == NULL)
        {
            delete current;
            current = NULL;
        }
        //Case 2: Has One Child
        //Case 2.1: Has Right Child 
        else if (current->left == NULL)
        {
            node *temp = current;
            current = current->right;
            delete temp;
        }
        //Case 2.2: Has Left Child
        else if (current->right == NULL)
        {
            node *temp = current;
            current = current->left;
            delete temp;
        }
        else
        {
            node *temp = minNode(current->right);
            current->data = temp->data;
            current->right = deleteNode(current->right,temp->data);
        }
    }
    return current;    
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
    cout<<"Binary Search Tree Recursive\n";
    while (true)
    {
        int choise;
        menu();
        cout<<"Enter the option: ";
        cin>>choise;
        switch (choise)
        {
            case 1:
                int data;
                cout<<"Enter Data: ";
                cin>>data;
                root = insertNode(root,data);
                break;
            case 2:
                if(root == NULL)
                    cout<<"Tree is empty :(\n";    
                else
                {
                    int key;
                    cout<<"Enter data to be Search: ";
                    cin>>key;
                    if(search(root,key))
                        cout<<"Data Found :)\n";
                    else
                        cout<<"Data not found :(\n";
                }
                break;
            case 3:
                if(root == NULL)
                    cout<<"Tree is empty :(\n";
                else 
                {
                    preOrder(root);
                    cout<<"\n";
                }
                break;
            case 4:
                if(root == NULL)
                    cout<<"Tree is empty :(\n";
                else
                { 
                    inorder(root);
                    cout<<"\n";
                }
                break;
            case 5:
                if(root == NULL)
                    cout<<"Tree is empty :(\n";
                else
                { 
                    postOrder(root);
                    cout<<"\n";
                }
                break;
            case 6:
                if(root == NULL)
                    cout<<"Tree is empty :(\n";
                else
                {
                    int key;
                    cout<<"Enter data to be delete: ";
                    cin>>key;
                    flag = false;
                    root = deleteNode(root,key);
                    if (flag == true)
                        cout<<"Data deleted Successfully :)\n";
                    else
                        cout<<"Data not present in tree :(\n";
                }
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
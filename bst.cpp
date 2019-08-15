#include<iostream>
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

void inserNode()
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


int main()
{
    cout<<"Binary Search Tree\n"
    return 0;
}
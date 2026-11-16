/*Write a C program to create a binary search tree by inserting nodes and display the tree 
using non-recursive inorder traversal.*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* left;      //smaller values
    struct node* right;     //larger values
    int data;
};
struct node* insert_node(struct node* root, int val)
{
    if(root==NULL)      //empty spot found, create the new node here
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->data=val;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if(val<root->data)
    {
        root->left=insert_node(root->left,val);     //smaller value goes to the left subtree
    }
    else if(val>root->data)
    {
        root->right=insert_node(root->right,val);   //larger value goes to the right subtree
    }
    else
    {
        printf("Duplicate number %d cannot be inserted \n",val);        //BST does not allow duplicates
    }
    return root;
}
#define MAX 100
struct node *stack[MAX];
int top;
void inorder_traversal(struct node* root)
{
    struct node* ptr;
    top=1;
    stack[top]=NULL;        //initialize stack with NULL
    ptr=root;
    while(ptr!=NULL)
    {
        top++;
        stack[top]=ptr;     //push current node onto stack
        ptr=ptr->left;      //move to the leftmost node
    }
    ptr=stack[top];
    top--;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);        //visit the node
        if(ptr->right!=NULL)
        {
            ptr=ptr->right;     //move to right subtree
            while(ptr!=NULL)
            {
                top++;
                stack[top]=ptr;     //push nodes while moving left
                ptr=ptr->left;
            }
        }
        ptr=stack[top];     //pop the next node from stack
        top--;
    }
}
int main()
{
    struct node *root=NULL;
    int n;
    int i;
    int val;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter %d values:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        root=insert_node(root,val);
    }
    printf("Inorder (non-recursive): ");
    inorder_traversal(root);
    printf("\n");
    return 0;
}
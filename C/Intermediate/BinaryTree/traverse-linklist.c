/*Write a C program to create a binary tree using recursion and perform inorder, preorder and 
postorder traversals.*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create()       //builds the tree recursively in preorder, returns NULL for -1
{
    int x;
    scanf("%d",&x);
    if(x==-1)       //no node here, end this branch
    {
        return NULL;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    printf("Enter the value of left node ( enter -1 if there are no node) : ");
    newnode->left=create();     //build the left subtree
    printf("Enter the value of right node ( enter -1 if there are no node) : ");
    newnode->right=create();    //build the right subtree
    return newnode;
}
void preorder(struct node* root)        //Root,Left,Right
{
    if(root==NULL)      //empty subtree, nothing to print
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root)     //Left,Root,Right
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node* root)       //Left,Right,Root
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int main()
{
    struct node* root;
    printf("Enter the value of root (-1 if no root) : ");
    root=create();      //returns the address of the root node
    printf("\ninorder : ");
    inorder(root);
    printf("\npreorder : ");
    preorder(root);
    printf("\npostorder : ");
    postorder(root);
    printf("\n");
    return 0;
}
/*Write a C program to create a binary tree using recursion, count the number of leaf nodes and
 display the whole tree.*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* left;
    struct node* right;
    int data;
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
    printf("Enter the value of the left node (-1 if no node)\n");
    newnode->left=create();     //build the left subtree
    printf("Enter the value of the right node(-1 if no node)\n");
    newnode->right=create();    //build the right subtree
    return newnode;
}
void display(struct node* root)     //preorder print, -1 for every empty position
{
    if(root==NULL)
    {
        printf("-1 ");      //empty position
        return;
    }
    printf("%d ",root->data);
    display(root->left);
    display(root->right);
}
int leaf_count(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)     //a node with no children is a leaf
    {
        return 1;
    }
    return(leaf_count(root->left)+leaf_count(root->right));     //leaves in left + leaves in right
}
int main()
{
    struct node* root;
    printf("Enter the value of root (enter -1 if there is no value)\n");
    root=create();
    printf("total number of leaf node : ");
    printf("%d ",leaf_count(root));
    printf("\n");
    printf("Our binary tree (preorder, -1 for empty) : ");
    display(root);
    printf("\n");
    return 0;
}
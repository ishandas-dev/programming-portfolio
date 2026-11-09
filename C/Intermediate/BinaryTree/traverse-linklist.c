#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create()
{
    int x;
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    printf("Enter the value of left node ( enter -1 if there are no node) : ");
    newnode->left=create();
    printf("Enter the value of right node ( enter -1 if there are no node) : ");
    newnode->right=create();
    return newnode;
}
void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node* root)
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
    root=create();
    printf("\ninorder : ");
    inorder(root);
    printf("\npreorder : ");
    preorder(root);
    printf("\npostorder : ");
    postorder(root);
    printf("\n");
    return 0;
}
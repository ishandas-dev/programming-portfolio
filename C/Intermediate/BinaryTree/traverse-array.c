/*Write a C program to represent a binary tree using an array and perform preorder, inorder and 
postorder traversals.*/

#include<stdio.h>
#define MAX 100
int tree[MAX];      //level order array, -1 means empty node
int n;               //number of array positions, including -1 placeholders
void preorder(int i) //Root,Left,Right
{
    if(i>=n||tree[i]==-1) //out of range or empty node
    {
        return;
    }
    printf("%d ",tree[i]);
    preorder(2*i+1);     //left child
    preorder(2*i+2);     //right child
}
void inorder(int i)     //Left,Root,Right
{
    if(i>=n||tree[i]==-1)
    {
        return;
    }
    inorder(2*i+1);
    printf("%d ",tree[i]);
    inorder(2*i+2);
}
void postorder(int i)   //Left,Right,Root
{
    if(i>=n||tree[i]==-1)
    {
        return;
    }
    postorder(2*i+1);
    postorder(2*i+2);
    printf("%d ",tree[i]);
}
int main()
{
    printf("Enter number of nodes in the binary tree : ");
    scanf("%d",&n);
    printf("Enter the elements in the binary tree\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tree[i]);       //enter -1 for a missing node
    }
    printf("preorder: ");
    preorder(0);            //root is at index 0
    printf("\n");
    printf("inorder: ");
    inorder(0);
    printf("\n");
    printf("postorder: ");
    postorder(0);
    printf("\n");
    return 0;
}
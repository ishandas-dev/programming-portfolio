/*Write a C program to create a binary search tree by inserting nodes and display it using inorder traversal.*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* left;      //smaller values
    struct node* right;     //larger values
    int data;
};
struct node* insert_node(struct node* root,int key)
{
    if(root==NULL)      //empty spot found, create the new node here
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->data=key;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if(key<root->data)
    {
        root->left=insert_node(root->left,key);     //smaller value goes to the left subtree
    }
    else if(key>root->data)
    {
        root->right=insert_node(root->right,key);   //larger value goes to the right subtree
    }
    else
    {
        printf("Duplicate nodes %d are not inserted\n",key);        //BST does not allow duplicates
    }
    return root;
}
void inorder(struct node* root)     //Left,Root,Right (prints in sorted order for a BST)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main()
{
    int i, val=0, n=0;
    struct node* root=NULL;
    printf("Enter the number of nodes in binary tree : ");
    scanf("%d",&n);
    printf("Enter the values in the binary tree\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        root=insert_node(root,val);     //root is updated when the first node is inserted
    }
    printf("Inorder after insertion : ");
    inorder(root);
    printf("\n");
    return 0;
}
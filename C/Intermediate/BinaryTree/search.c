/*Write a C program to create a binary search tree by inserting nodes, display it using inorder
traversal and search for a given element in the tree.*/

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
        printf("duplicated number %d is not inserted \n",val);      //BST does not allow duplicates
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
struct node* search_node(struct node* root,int key)     //returns the node if found, otherwise NULL
{
    if(root==NULL||root->data==key)     //not found or found
    {
        return root;
    }
    else if(key<root->data)
    {
        return search_node(root->left,key);
    }
    else
    {
        return search_node(root->right,key);
    }
}
int main()
{
    struct node* root=NULL;
    int i,val=0,n=0;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    printf("Enter the values in the node\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        root=insert_node(root,val);     //root is updated when the first node is inserted
    }
    printf("Our binary tree : ");
    inorder(root);
    int key;
    printf("\nEnter the number to be search : ");
    scanf("%d",&key);
    if(search_node(root,key)!=NULL)
    {
        printf("Our node is present in the binary tree\n");
    }
    else
    {
        printf("Our node is not present in the binary tree\n");
    }
    return 0;
}
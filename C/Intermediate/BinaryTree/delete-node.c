/*Write a C program to create a binary search tree by inserting nodes, delete a given node from 
the tree and display the tree using inorder traversal before and after deletion.*/

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
struct node* min_find(struct node* root)        //smallest value is the leftmost node
{
    while(root!=NULL&&root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
struct node* delete_node(struct node* root, int key)
{
    struct node* temp;
    if(root==NULL)      //key is not present in the tree
    {
        printf("%d value not found\n",key);
        return NULL;
    }
    if(key<root->data)
    {
        root->left=delete_node(root->left,key);     //key is in the left subtree
    }
    else if(key>root->data)
    {
        root->right=delete_node(root->right,key);   //key is in the right subtree
    }
    else        //node to be deleted if found
    {
        if(root->left==NULL)        //no left child (also covers the leaf node case)
        {
            temp=root->right;
            free(root);
            return temp;        //right child takes the place of the deleted node
        }
        else if(root->right==NULL)      //no right child
        {
            temp=root->left;
            free(root);
            return temp;        //left child takes the place of the deleted node
        }
        temp=min_find(root->right);     //two children: find inorder successor (smallest in right subtree)
        root->data=temp->data;      //copy the successor's value into this node
        root->right=delete_node(root->right,temp->data);        //delete the successor from the right subtree
    }
    return root;
}
void inorder(struct node *root)     //Left,Root,Right (prints in sorted order for a BST)
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
    printf("Inorder before deletion: ");
    inorder(root);
    printf("\nEnter value to delete: ");
    scanf("%d",&val);
    root=delete_node(root,val);     //root is updated in case the root node itself is deleted
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}
/*Write a C program to create a binary search tree by inserting nodes, delete the entire tree and 
display the tree using inorder traversal before and after deletion.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node* left; //smaller values
struct node* right; //larger values
int data;
};
struct node* insert_node(struct node* root,int val)
{
if(root==NULL) //empty spot found, create the new node here
{
root=(struct node*)malloc(sizeof(struct node));
root->data=val;
root->left=NULL;
root->right=NULL;
return root;
}
if(val<root->data)
{
root->left=insert_node(root->left,val); //smaller value goes to the left subtree
}
else if(val>root->data)
{
root->right=insert_node(root->right,val); //larger value goes to the right subtree
}
else
{
printf("duplicated number %d is not inserted",val); //BST does not allow duplicates
}
return root;
}
struct node* delete_tree(struct node* root) //deletes the whole tree in postorder, returns NULL
{
if(root==NULL)
{
return NULL;
}
delete_tree(root->left); //free the left subtree first
delete_tree(root->right); //then the right subtree
free(root); //root is freed last, after its children
return NULL; //so the caller's root becomes NULL
}
void inorder(struct node* root) //Left,Root,Right (prints in sorted order for a BST)
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
root=insert_node(root,val);
}
printf("Inorder before deletion : ");
inorder(root);
root=delete_tree(root); //root must be reassigned, otherwise it keeps pointing to freed memory
printf("\nInorder after deletion : ");
if(root==NULL)
{
printf("tree is empty");
}
printf("\n");
return 0;
}
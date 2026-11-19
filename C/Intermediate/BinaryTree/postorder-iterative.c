/*Write a C program to create a binary search tree by inserting nodes and display the tree
using non-recursive postorder traversal.*/

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
struct node* stack[MAX];
int mark[MAX];
int top;
void postorder(struct node* root)
{
    struct node* ptr=root;
    top=1;
    int neg;
    stack[top]=NULL;        //initialize stack with NULL
    mark[top]=0;
    while(1)
    {
        while(ptr!=NULL)
        {
            top++;
            stack[top]=ptr;     //push current node onto stack
            mark[top]=0;       //mark 0 means node is not ready to be printed
            if(ptr->right!=NULL)
            {
                top++;
                stack[top]=ptr->right;      //push right child onto stack
                mark[top]=1;       //mark 1 means right subtree is pending
            }
            ptr=ptr->left;      //move to left subtree first
        }
        ptr=stack[top];
        neg=mark[top];
        top--;
        while(ptr!=NULL&&neg==0)
        {
            printf("%d ",ptr->data);        //visit node after left and right subtrees
            ptr=stack[top];
            neg=mark[top];
            top--;
        }
        if(ptr!=NULL&&neg==1)
        {
            continue;       //process the pending right subtree
        }
        break;
    }
}
int main()
{
    struct node* root=NULL;
    int n, val, i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter %d values:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        root=insert_node(root,val);
    }
    printf("Postorder (non-recursive): ");
    postorder(root);
    printf("\n");
    return 0;
}
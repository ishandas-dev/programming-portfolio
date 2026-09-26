#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* InsertAtFirst(struct node* head,int value)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    return newnode;
}
void display(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main()
{
    int value=0,n=0;
    struct node* head=NULL;
    printf("How many nodes do you want in the Linklist\n",n);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of node %d ",i);
        scanf("%d",&value); 
        head=InsertAtFirst(head,value);
    } 
    printf("\nLinked list: ");
    display(head);
    return 0;
}

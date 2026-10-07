#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* InsertAtFirst(struct node* head,int value)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=head;
    if(head!=NULL)
    {
        head->prev=newnode;
    }
    head=newnode;
    return head;
}
void display(struct node* head)
{
    if(head==NULL)
    {
        printf("Our Doubly LinkList is empty\n");
        return;
    }
    struct node* ptr=head;
    printf("Our Doubly LinkList in forward direction : ");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    printf("Our Doubly LinkList in backward direction : ");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->prev;
    }
    printf("NULL\n");
}
int main()
{
    int value=0,n=0;
    struct node* head=NULL;
    struct node* tail=NULL;
    printf("Enter the number of nodes you want in your Doubly LinkList : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of node at index %d : ",i);
        scanf("%d",&value);
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            temp->prev=NULL;
            head=temp;
            tail=temp;
        }
        else
        {
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
    }
    printf("Enter the value you want to insert : ");
    scanf("%d",&value);
    printf("Our Doubly LinkList before Insertion :\n");
    display(head);
    head=InsertAtFirst(head,value);
    printf("Our Doubly LinkList after Insertion :\n");
    display(head);
    return 0;
}
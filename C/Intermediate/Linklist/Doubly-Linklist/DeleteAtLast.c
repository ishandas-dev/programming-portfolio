#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* DeleteAtLast(struct node* head)
{
    if(head==NULL)
    {
        printf("Our Doubly LinkList is empty so we cannot delete\n");
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    struct node* ptr=head;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
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
    printf("Our Doubly LinkList before Deletion:\n");
    display(head);
    head=DeleteAtLast(head);
    printf("Our Doubly LinkList after Deletion :\n");
    display(head);
    return 0;
}
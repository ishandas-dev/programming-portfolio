#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* next;
    int data;
};
struct node* InsertAfterValue(struct node* head, int value, int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    struct node* ptr=head;
    if(head->data==val)
    {
        newnode->next=head->next;
        head->next=newnode;
    }
    do{
        ptr=ptr->next;
    }while(ptr->next!=head&&ptr!=val);
    newnode->next=ptr->next;
    ptr->next=newnode;
    return head;
}
void display(struct node* head)
{
    if(head==NULL)
    {
        printf("Our cicular LinkList is empty\n");
        return;
    }
    struct node* ptr=head;
    do{
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("%d\n",head->data);
}
int main()
{
    int n,value;
    struct node* head=NULL;
    struct node* tail=NULL;
    printf("Enter the number of nodes in our circular Linklist : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of the node at index %d : ",i);
        scanf("%d",&value);
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
        tail->next=head;
    }
        printf("Our circular LinkList before insertion is : ");
        display(head);
        printf("Enter the value you want to insert at first of our circular linklist : ");
        scanf("%d",&value);
        head=InsertAtFirst(head,value);
        printf("Our circular Linklist after insertion is : ");
        display(head);
        return 0;
}


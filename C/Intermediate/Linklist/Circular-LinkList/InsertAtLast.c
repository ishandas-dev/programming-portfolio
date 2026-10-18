#include<stdio.h>
#include<Stdlib.h>
struct node{
    struct node* next;
    int data;
};
struct node* InsertAtLast(struct node* head, int value)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* ptr=head;
    newnode->data=value;
    do{
        ptr=ptr->next;
    }while(ptr->next!=head);
    ptr->next=newnode;
    newnode->next=head;
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
        printf("Enter the value you want to insert at last of our circular linklist : ");
        scanf("%d",&value);
        head=InsertAtLast(head,value);
        printf("Our circular Linklist after insertion is : ");
        display(head);
        return 0;
}

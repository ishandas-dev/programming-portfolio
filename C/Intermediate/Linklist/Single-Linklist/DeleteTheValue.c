#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* DeleteTheValue(struct node* head,int value)
{
    if(head->data==value)
    {
        struct node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    struct node* ptr=head;
    while(ptr->next!=NULL&&ptr->next->data!=value)
    {
        ptr=ptr->next;
    }
    if(ptr->next==NULL) 
    {
        printf("The given value is not in the LinkList so the LinkList remains the same as : ");
        return head;
    }
    struct node* temp=ptr->next;
    ptr->next=ptr->next->next;
    free(temp);
    return head;
}
void display(struct node* head)
{
    if(head==NULL)
    {
        printf("The LinkList is empty\n");
        return ;
    }
    else
    { 
        struct node* ptr=head;
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    int n=0,value=0;
    struct node* head=NULL;
    struct node* tail=NULL;
    printf("Enter the number of nodes you want in your LinkList : ");
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
    }
    printf("Our LinkList before the insertion is : ");
    display(head);
    printf("Enter the value you want to delete from the LinkList : ");
    scanf("%d",&value);
    printf("Our Linklist after the deletion is : ");
    head=DeleteTheValue(head,value);
    display(head);
    return 0;
}
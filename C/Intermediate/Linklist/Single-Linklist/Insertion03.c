#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* create(int value) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void InsertAtFirst(int value)
{
    struct node *newnode = create(value);
    newnode->next=head;
    head=newnode;
    printf("Inserted %d at the beginning\n",value);
}
void InsertAtLast(int value)
{
    struct node *newnode = create(value);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    else
    {
        struct node *ptr = head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
    }
}
void InsertAfterValue(int num,int value)
{
    struct node* newnode= create(value);
    struct node* ptr=head;
    if(ptr==NULL)
    {
        printf("The linklist is empty\n");
        return;
    }
    while(ptr!=NULL&&ptr->data!=num)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        printf("The given number %d is not found\n",num);
        free(newnode);
        return;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;
    printf("Inserted %d after the given value\n",value);
}
void InsertAtPosition(int pos,int value)
{
    struct node* newnode= create(value);
    struct node* ptr=head;
    if(ptr==NULL)
    {
        printf("The linklist is empty\n");
        return;
    }
    if(pos==1)
    {
        free(newnode);
        InsertAtFirst(value);
        return;
    }
    int i=1;
    while(ptr!=NULL&&i<pos-1)
    {
        ptr=ptr->next;
        i++;
    }
    if(ptr==NULL)
    {
        printf("The given number position %d is out of bound \n",pos);
        free(newnode);
        return;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;
    printf("Inserted %d at the given position",value);
}
void display()
{
    if(head==NULL)
    {
    printf("The list is empty\n");
    return;
    }
    else
    {
        struct node* ptr=head;
        printf("Our LinkList is\n");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
    printf("NULL\n");
}
int main()
{
    int i,value=0,n=0,ch=0,num=0,pos=0,cont=0;
    printf("How many nodes do you want in the Linklist\n",n);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the value of the node \n");
        scanf("%d",&value);
        InsertAtLast(value);
    }
    display();
    do{
        printf("Below are the operations for insertion , choose as per your choice\n");
        printf("Enter 1 for insertion at first\n");
        printf("Enter 2 for insertion at last\n");
        printf("Enter 3 for insertion after a given value\n");
        printf("Enter 4 for insertion at a given position\n");
        printf("Enter 5 for exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the value \n");
            scanf("%d",&value);
            InsertAtFirst(value);
            break;
            case 2:
            printf("Enter the value \n");
            scanf("%d",&value);
            InsertAtLast(value);
            printf("Inserted %d at the last\n",value);
            break;
            case 3:
            printf("Enter the number after which the value is to be inserted\n");
            scanf("%d",&num);
            printf("Enter the value \n");
            scanf("%d",&value);
            InsertAfterValue(num,value);
            break;
            case 4:
            printf("Enter the position after which the value is to be inserted\n");
            scanf("%d",&pos);
            printf("Enter the value \n");
            scanf("%d",&value);
            InsertAtPosition(pos,value);
            break;
            case 5:
            printf("Exiting program\n");
            exit(0);
            break;
            default:
            printf("Invalid input\n");
        }
        display();
        printf("Do you want to continue\n(1=YES,0=NO)");
        scanf("%d",&cont);
    } while(cont==1);
    printf("Exiting program\n");
    return 0;
}

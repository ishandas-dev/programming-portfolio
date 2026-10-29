#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* next;
    int data;
};
struct node* front=NULL;
struct node* rear=NULL;
int is_empty()
{
    return front==NULL;
}
int is_full()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        return 1;
    }
    free(temp);
    return 0;
}
void enqueue(int x)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Queue overflow\n");
        return;
    }
    newnode->data=x;
    newnode->next=NULL;
    if(is_empty())
    {   
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    printf("Enqueued %d \n",x);
}
int dequeue()
{
    if(is_empty())
    {
        printf("Underflow\n");
        return -1;
    }
    struct node* temp=front;
    int x=front->data;
    front=front->next;
    if(front==NULL)
    {
        rear=NULL;
    }
    free(temp);
    return x;
}
int peek()
{
    if(is_empty())
    {
        printf("Underflow\n");
        return -1;
    }
    return front->data;
}
void display()
{
    struct node* temp=front;
    if(is_empty())
    {
        printf("Queue is empty\n");
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int con=0;
    int ch=0;
    int x;
    do{
        printf("Enter the following numbers for following functions : \n");
        printf("Enter 1. for Enqueue\n");
        printf("Enter 2. for Dequeue\n");
        printf("Enter 3. for empty\n");
        printf("Enter 4. for full\n");
        printf("Enter 5. for peek\n");
        printf("Enter 6. for display\n");
        printf("Enter 7 for exiting the program\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the value of x : ");
            scanf("%d",&x);
            enqueue(x);
            break;
            case 2:
            x=dequeue();
            if(x!=-1)
            {
                printf("dequeued : %d\n",x);
            }
            break;
            case 3:
            if(is_empty())
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
            case 4:
            if(is_full())
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Queue is not full\n");
            }
            break;
            case 5:
            x=peek();  
            if(x!=-1)
            {
                printf("peek : %d\n",x);
            }
            break;
            case 6:
            display();
            break;
            case 7:
            printf("Existing from program\n");
            exit(0);
            break;
            default:
            printf("Invalid choice , please choose again\n");
        }
        printf("Do you want to continue? if yes then select 1 otherwise 0 : ");
        scanf("%d",&con);
    }while(con==1);
    return 0;
}
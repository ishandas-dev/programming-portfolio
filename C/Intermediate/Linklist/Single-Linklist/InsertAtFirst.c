/*Implement a singly linked list where the user first builds the list by entering a specified number of 
nodes with their values (inserted at the end, in the order entered). After the list is built and displayed,
the user enters one more value, which is inserted at the beginning (first position) of the list. Display the
list before and after this insertion to verify the operation.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the singly linked list
struct node{
    int data;
    struct node* next;
};

//Function for inserting a new node at the beginning of the list
struct node* InsertAtFirst(struct node* head, int value) //Takes the current head and the value to insert,
{
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=value;    //store the given value in the new node
    newnode->next=head;     //new node points to the current first node
    return newnode;         //returning the list with the new node at first
}
void display(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;    //move to the next node
    }
    printf("NULL\n");       //marks the end of the node
}
int main()
{
    int n=0,value=0;
    struct node* head=NULL;     //head always points to the first node
    struct node* tail=NULL;     //tail tracks the last node for quick end-insertion
    printf("Enter the number of nodes in the Linklist: ");
    scanf("%d",&n);

    //Building the initial list by inserting each value at the end
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of the node %d: ",i);
        scanf("%d",&value);
        struct node* temp=(struct node*)malloc(sizeof(struct node));    //Create and initialize a new node
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;      //List was empty, so this new node becomes the head
            tail=temp;      //It is also the only node, so it becomes the tail too
        }
        else
        {
            tail->next=temp;     //attach the new node right after the current last node
            tail=temp;           //move tail forward, since this new node is now the last one
        }
    }
    printf("Our Linklist before insertion:\n");
    display(head);      
    printf("Enter the node you want to enter at first: ");
    scanf("%d",&value);
    head=InsertAtFirst(head,value);      //head is updated to the new first node
    printf("Our Linklist after insertion:\n");
    display(head);
    return 0;
}

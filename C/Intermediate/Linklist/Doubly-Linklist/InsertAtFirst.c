/*Implement a doubly linked list where the user first builds the list by entering a specified number of 
nodes with their values (added at the end, in the order entered).After the list is built and displayed
in both forward and backward directions, the user enters one more value, which is inserted at the beginning 
(first position) of the list. Display the list before and after this insertion to verify that both
the next and prev pointers are updated correctly.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the doubly linked list,prev points to the previous node and next to the following node
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

//Inserts a new node with the given value at the beginning of the list
struct node* InsertAtFirst(struct node* head,int value)     //takes the current head and the value to insert,returns the new head of the updated list
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;    //store the given value in the new node
    newnode->prev=NULL;     //the new node will be the first, so nothing comes before it
    newnode->next=head;     //new node points forward to the current first node(NULL if the list was empty)
    if(head!=NULL)
    {
        head->prev=newnode; //old first node points back to the new node
    }
    head=newnode;           //new node is now the first node of the list
    return head;            //return the list with the new node at first
}

//Prints all node values in forward direction, then in backward direction
void display(struct node* head)
{
    if(head==NULL)
    {
        printf("Our Doubly LinkList is empty\n");   //nothing to traverse
        return;
    }
    struct node* ptr=head;
    printf("Our Doubly LinkList in forward direction : ");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;      //move forward using next
    }
    printf("NULL\n");
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;      //move to the last node to start the backward traversal
    }
    printf("Our Doubly LinkList in backward direction : ");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->prev;      //move backward using prev
    }
    printf("NULL\n");
}

int main()
{
    int value=0,n=0;
    struct node* head=NULL;     //head always points to the first node
    struct node* tail=NULL;     //tail tracks the last node for quick end-insertion
    printf("Enter the number of nodes you want in your Doubly LinkList : ");
    scanf("%d",&n);

    //Building the initial list by adding each value at the end
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of node at index %d : ",i);
        scanf("%d",&value);
        struct node* temp=(struct node*)malloc(sizeof(struct node));    //create a new node
        temp->data=value;   //store the entered value
        temp->next=NULL;    //it will be the last node for now
        if(head==NULL)
        {
            temp->prev=NULL;    //first node, nothing comes before it
            head=temp;          //list was empty, so this node becomes the head
            tail=temp;          //it is also the only node, so it becomes the tail too
        }
        else
        {
            temp->prev=tail;    //new node points back to the current last node
            tail->next=temp;    //attach the new node right after the current last node
            tail=temp;          //move tail forward, since this node is now the last one
        }
    }
    printf("Enter the value you want to insert : ");
    scanf("%d",&value);
    printf("Our Doubly LinkList before Insertion :\n");
    display(head);                   //Show the list as built, before the first-position insertion
    head=InsertAtFirst(head,value);  //returns the new head of the updated list
    printf("Our Doubly LinkList after Insertion :\n");
    display(head);                  //Show the list after inserting the new value at the beginning
    return 0;
}
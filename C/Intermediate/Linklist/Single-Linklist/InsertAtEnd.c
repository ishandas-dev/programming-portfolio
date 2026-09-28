/*Implement a singly linked list where the user first builds the list by entering a specified number of nodes
with their values (added at the end, in the order entered). After the list is built and displayed,
the user enters one more value, which is inserted at the end (last position) of the list.
Display the list before and after this insertion to verify the operation.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the singly linked list
struct node{
    int data;
    struct node* next;
};

//Function for inserting a new node at the end of the list
struct node* InsertAtLast(struct node* head,int value)      //takes the current head and the value to insert, returns the head of the updated list
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* ptr=head;     //walk with ptr so head keeps pointing to the first node
    newnode->data=value;      //store the given value in the new node
    newnode->next=NULL;      //the new node will be the last, so nothing comes after it
    if(head==NULL)
    {
        return newnode;     //list was empty, so the new node itself becomes the head
    }
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;      //keep moving until ptr reaches the last node
    }
    ptr->next=newnode;      //attach the new node after the current last node
    return head;            //head is unchanged so it returns the updated list
}   

//traverses and prints all node values in the list, ending with NULL
void display(struct node* head)
{
    if(head==NULL)
    {
        printf("The LinkList is empty\n");  //our list is empty so no point of traverse
        return;
    }
    struct node* ptr=head;      // walk with ptr so head is not disturbed
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data); 
        ptr=ptr->next;          //move to the next node
    }
    printf("NULL\n");           //marks the end of the node
}
int main()
{
    int n=0,value=0;
    struct node* head=NULL;     //head always points to the first node
    struct node*tail=NULL;      //tail tracks the last node for quick end-insertion
    printf("Enter the number of nodes in our LinkList : ");
    scanf("%d",&n);

    //Building the initial list by inserting each value at the end
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of the node at index %d : ",i);
        scanf("%d",&value);
        struct node* temp=(struct node*)malloc(sizeof(struct node));     //Create and initialize a new node
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;  //List was empty, so this new node becomes the head
            tail=temp;  //It is also the only node, so it becomes the tail too
        }
        else
        {
            tail->next=temp;    //attach the new node right after the current last node
            tail=temp;          //move tail forward, since this new node is now the last one
        }
    }
    printf("Our Linklist before the insertion: ");
    display(head);              //calling the display function by passing head to print the linklist before insertion
    printf("Enter the value you want to insert at last : ");
    scanf("%d",&value);
    head=InsertAtLast(head,value);       //head is updated to the new first node
    printf("Our Linklist after the insertion: ");
    display(head);              //calling the display function by passing head to print the linklist before insertion
    return 0;
}
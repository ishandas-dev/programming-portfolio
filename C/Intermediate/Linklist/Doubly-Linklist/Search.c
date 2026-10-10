/*Implement a doubly linked list where the user first builds the list by entering a specified number of nodes 
with their values (added at the end, in the order entered). Display the list in both forward and backward
directions. Then take a value from the user and search for it by traversing the list from the head. If the 
value is found, print the index at which it occurs, otherwise report that it is not present.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the doubly linked list, prev points to the previous node and next to the following node
struct node{
    int data;
    struct node* next;
    struct node* prev;
};

//Searches for the given value in the list starting from the head
struct node* Search(struct node* head, int value)      //Takes the head and the value to search, returns the node if found, otherwise NULL
{
    int index=0;
    struct node* ptr=head;     //walk with ptr so head keeps pointing to the first node
    while(ptr!=NULL)
    {
        if(ptr->data==value)
        {
            printf("The search number %d is found at index %d from front ",value,index);
            return ptr;     //value found, return the node that holds it
        }
        ptr=ptr->next;      //move to the next node
        index++;            //tracks the index of the node currently being checked
    }
    printf("The search number is not present in the LinkList");
    return NULL;
}

//Prints all node values in forward direction, then in backward direction
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
        ptr=ptr->prev;     //move backward using prev
    }
    printf("NULL\n");
}
int main()
{
    int value=0,n=0;
    struct node* head=NULL;      //head always points to the first node
    struct node* tail=NULL;      //tail tracks the last node for quick end-insertion
    printf("Enter the number of nodes you want in your Doubly LinkList : ");
    scanf("%d",&n);

    //Building the initial list by inserting each value at the end
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of node at index %d : ",i);
        scanf("%d",&value);
        struct node* temp=(struct node*)malloc(sizeof(struct node));    //create a new node
        temp->data=value;     //store the entered value
        temp->next=NULL;      //it will be the last node for now
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
            tail=temp;           //move tail forward, since this node is now the last one
        }
    }
    display(head);
    printf("Enter the value to be searched : ");    //Take the value to search from the user and search for it
    scanf("%d",&value);
    Search(head,value);
    return 0;
}



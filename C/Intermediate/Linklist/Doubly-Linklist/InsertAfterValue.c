/*Implement a doubly linked list where the user first builds the list by entering a specified number of 
nodes with their values (added at the end, in the order entered).After the list is built and displayed
in both forward and backward directions, the user enters a value to search for and a new value, which is
inserted right after the node holding the searched value. Display the list before and after this insertion
to verify that both the next and prev pointers are updated correctly.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the doubly linked list,prev points to the previous node and next to the following node
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

//Inserts a new node with the given value right after the node that holds the searched value
struct node* InsertAfterValue(struct node* head,int value,int val)     //takes the current head,the value to insert and the value to insert after,returns the head of the updated list
{
    if(head==NULL)
    {
        printf("Our Doubly LinkList is empty\n");   //nothing to search in
        return head;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;    //store the value to be inserted in the new node
    newnode->prev=NULL;     //set to NULL for now, updated below once the position is found
    newnode->next=NULL;     //set to NULL for now, updated below once the position is found
    struct node* ptr=head;  //walk with ptr so head keeps pointing to the first node
    while(ptr->next!=NULL&&ptr->data!=val)
    {
        ptr=ptr->next;      //keep moving until ptr reaches the node holding val or the last node
    }
    if(ptr->data!=val)
    {
        printf("The value does not exist in our doubly LinkList\n");    //val was not found in any node,including the last one
        free(newnode);      //newnode was allocated but never used,so release it
        return head;
    }
    newnode->next=ptr->next;    //new node points forward to the node that used to come after ptr
    ptr->next=newnode;          //ptr points forward to the new node
    newnode->prev=ptr;          //new node points back to ptr
    if(newnode->next!=NULL)
    {
        newnode->next->prev=newnode;    //the node after the new node points back to it(skipped when ptr was the last node)
    }
    return head;            //head is unchanged,return the updated list
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
    int value=0,n=0,val=0;
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
    printf("Enter the value after which you want to insert : ");
    scanf("%d",&val);           //val is the existing value to search for
    printf("Enter the value you want to insert in the LinkList : ");
    scanf("%d",&value);         //value is the new value to be inserted
    printf("Our Doubly LinkList before Insertion :\n");
    display(head);                              //Show the list as built, before the insertion
    head=InsertAfterValue(head,value,val);      //returns the head of the updated list
    printf("Our Doubly LinkList after Insertion :\n");
    display(head);                              //Show the list after inserting the new value after val
    return 0;
}
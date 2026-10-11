/*Write a C program to create a Doubly Linked List of n nodes and insert a new node at a given position.
Display the list in both forward and backward direction,before and after the insertion.
Input : number of nodes n, the value of each node, the position and the value to insert.
Output: the Doubly Linked List before and after insertion (forward and backward).*/

#include<stdio.h>
#include<stdlib.h>

//Structure of a node in the Doubly Linked List
struct node{
    int data;
    struct node* next;       //pointer to the next node
    struct node* prev;      //pointer to the previous node
};

//Function to insert a new node with the given value at position pos (0-based index)
struct node* InsertAtPosition(struct node* head,int value,int pos)
{

    // create a new node and store the value in it
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;

    //Case 1: insertion at the beginning
    if(pos==0)
    {
        newnode->next=head;      //new node points forward to the old head
        if(head!=NULL)
        {
            head->prev=newnode;  //old head points back to the new node
        }
        head=newnode;           //new node becomes the head
        return head;
    }

    //Case 2: insertion at the middle or the end
    struct node* ptr=head;
    int i=0;

    // move ptr to the node just before the required position
    while(ptr->next!=NULL&&i<pos-1)
    {
        ptr=ptr->next;
        i++;
    }
    if(ptr==NULL)
    {
        printf("The entered position is not in the Doubly LinkList\n");
        return head;
    }
    newnode->next=ptr->next;    //link the new node between ptr and ptr->next
    newnode->prev=ptr;

    //if ptr was not the last node, the next node must point back to the new node
    if(ptr->next!=NULL)
    {
        ptr->next->prev=newnode;
    }
    ptr->next=newnode;      //ptr now points forward to the new node
    return head;
}

//display the list in forward and backward direction
void display(struct node* head)
{
    if(head==NULL)
    {
        printf("Our Doubly LinkList is empty\n");
        return;
    }
    struct node* ptr=head;

    //forward traversal using next pointers
    printf("Our Doubly LinkList in forward direction : ");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
    ptr=head;

    //move ptr to the last node
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }

    //backward traversal using prev pointers
    printf("Our Doubly LinkList in backward direction : ");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->prev;
    }
    printf("NULL\n");
}
int main()
{
    int value=0,n=0,pos;
    struct node* head=NULL;    //head points to the first node
    struct node* tail=NULL;    //tail points to the last node
    printf("Enter the number of nodes you want in your Doubly LinkList : ");
    scanf("%d",&n);

    //create the list by adding each new node at the end
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of node at index %d : ",i);
        scanf("%d",&value);
        struct node* temp=(struct node*)malloc(sizeof(struct node));
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
            tail=temp;          //move tail forward, since this node is now the last one
        }
    }

    //take the position and value for insertion
    printf("Enter the position at which you want to insert : ");
    scanf("%d",&pos);
    printf("Enter the value you want to insert at position %d : ",pos);
    scanf("%d",&value);
    printf("Our Doubly LinkList before Insertion :\n");
    display(head);                           //display the list before insertion
    head=InsertAtPosition(head,value,pos);   //insert the new node
    printf("Our Doubly LinkList after Insertion :\n");
    display(head);                           //display the list after insertion
    return 0;
}
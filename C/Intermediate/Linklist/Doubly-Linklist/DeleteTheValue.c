/*Implement a doubly linked list where the user first builds the list by entering a specified number of 
nodes with their values (added at the end, in the order entered).After the list is built and displayed
in both forward and backward directions, the user enters a value to be deleted. The node holding that
value is removed from the list. Display the list before and after this deletion to verify that both
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

//Deletes the first node that holds the given value from the list
struct node* DeleteTheValue(struct node* head,int value)    //takes the current head and the value to delete,returns the head of the updated list
{
    if(head==NULL)
    {
        printf("There is no element to delete\n");  //nothing to delete from
        return NULL;
    }
    struct node* ptr=head;  //walk with ptr so head keeps pointing to the first node
    if(head->data==value)
    {
        head=head->next;    //move head forward,the second node becomes the first
        if(head!=NULL)
        {
            head->prev=NULL;    //new first node has nothing before it(skipped when the list had only one node)
        }
        free(ptr);          //release the old first node
        return head;
    }
    while(ptr->next!=NULL&&ptr->next->data!=value)
    {
        ptr=ptr->next;      //stop at the node just before the one holding the value
    }
    if(ptr->next==NULL)
    {
        printf("The given value does not exist in our Doubly LinkList\n");  //reached the end without a match
        return head;
    }
    struct node* temp=ptr->next;    //temp is the node to be deleted
    ptr->next=temp->next;           //skip over temp going forward
    if(temp->next!=NULL)
    {
        temp->next->prev=ptr;       //skip over temp going backward(skipped when temp was the last node)
    }
    free(temp);             //release the deleted node
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
    printf("Enter the value you want to delete from Our Doubly LinkList : ");
    scanf("%d",&value);
    printf("Our Doubly LinkList before Deletion :\n");
    display(head);                          //Show the list as built, before the deletion
    head=DeleteTheValue(head,value);        //returns the head of the updated list
    printf("Our Doubly LinkList after Deletion :\n");
    display(head);                          //Show the list after deleting the value
    return 0;
}
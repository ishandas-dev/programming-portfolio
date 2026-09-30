/*Implement a singly linked list where the user first builds the list by entering a specified number of nodes
with their values (added at the end, in the order entered). After the list is built and displayed,the user 
enters a new value and an existing value in the list, and the new value is inserted right after the first 
node containing that existing value.If the list is empty or the existing value is not found, an appropriate
message is displayed.Display the list before and after this insertion to verify the operation.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the singly linked list
struct node{
    int data;
    struct node* next;
};

//Function for inserting a new node after the first node that contains the value val
struct node* InsertAfterValue(struct node* head,int value,int val)      //takes the current head, the value to insert and the value to search for, returns the head of the updated list
{
    if (head == NULL)
    {
        printf("The LinkList is empty\n");      //nothing to search in, so no insertion is possible
        return head;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;      //store the given value in the new node
    struct node* ptr=head;    //walk with ptr so head keeps pointing to the first node
    while(ptr->data!=val&&ptr->next!=NULL)
    {
        ptr=ptr->next;      //keep moving until ptr reaches the node with val, or the last node
    }
    if(ptr->data!=val)
    {
        printf("The given value is not found\n");   //reached the last node and it is not val either
        return head;
    }
    newnode->next=ptr->next;    //first connect the new node to the node after ptr, so the rest of the list is not lost
    ptr->next=newnode;          //then connect ptr to the new node
    return head;                //head is unchanged so it returns the updated list
}

//traverses and prints all node values in the list, ending with NULL
void display(struct node* head)
{
    struct node* ptr=head;      //walk with ptr so head is not disturbed
    if(head==NULL)
    {
        printf("The given LinkList is Empty\n");    //our list is empty so no point of traverse
        return;
    }
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;          //move to the next node
    }
    printf("NULL\n");           //marks the end of the list
}
int main()
{
    int n=0,value=0,val=0;
    struct node* head=NULL;     //head always points to the first node
    struct node* tail=NULL;     //tail tracks the last node for quick end-insertion
    printf("Enter the number of nodes in the LinkList : ");
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
    printf("Our Linklist before insertion :");
    display(head);              //calling the display function by passing head to print the linklist before insertion
    printf("Enter the value which you want to insert : ");
    scanf("%d",&value);         //the new value to be inserted
    printf("Enter the value after which u want to insert the given value : ");
    scanf("%d",&val);           //the existing value after which the new node goes
    head=InsertAfterValue(head,value,val);    //head stays the same, since insertion is always after an existing node
    printf("Our Linklist after insertion :");
    display(head);              //calling the display function by passing head to print the linklist after insertion
    return 0;
}
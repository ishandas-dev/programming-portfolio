/*Implement a singly linked list where the user first builds the list by entering a specified number of nodes
with their values (added at the end, in the order entered). After the list is built and displayed,
the user enters one more value along with a position (0-based), and the value is inserted at that position.
Display the list before and after this insertion to verify the operation.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the singly linked list
struct node{
    int data;
    struct node* next;
};

//Function for inserting a new node at a given position (0-based) in the list
struct node* InsertAtPosition(struct node* head,int value,int pos)      //takes the current head, the value and the position, returns the head of the updated list
{
    //count the nodes of the list, to know which positions are valid
    struct node *count=head;
    int length=0;
    while(count!=NULL)
    {
        length++;   //keeping track of all the position of the LinkList
        count=count->next;
    }

    //valid positions are 0 to length
    if(pos<0||pos>length)
    {
        printf("The given position is not in our LinkList so our Linklist remains the same\n");
        return head;        //nothing is inserted, so the list stays unchanged
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;      //store the given value in the new node
    if(pos==0)
    {
        newnode->next=head;     //new node points to the old first node
        return newnode;         //new node itself becomes the head
    }
    struct node* ptr=head;     //walk with ptr so head keeps pointing to the first node
    int i=0;
    while(i<pos-1)
    {
        ptr=ptr->next;      //keep moving until ptr reaches the node just before the required position
        i++;
    }
    newnode->next=ptr->next;    //first connect the new node to the node after ptr, so the rest of the list is not lost
    ptr->next=newnode;          //then connect ptr to the new node
    return head;                //head is unchanged so it returns the updated list
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
    int n=0,value=0,pos=0;
    struct node* head=NULL;     //head always points to the first node
    struct node* tail=NULL;     //tail tracks the last node for quick end-insertion
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
    printf("Enter the value you want to insert : ");
    scanf("%d",&value);
    printf("Enter the position at which you want to insert the node : ");
    scanf("%d",&pos);
    head=InsertAtPosition(head,value,pos);       //head is updated to the new first node if pos is 0
    printf("Our Linklist after the insertion: ");
    display(head);              //calling the display function by passing head to print the linklist after insertion
    return 0;
}
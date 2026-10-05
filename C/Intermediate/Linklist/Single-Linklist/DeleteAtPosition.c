/*Implement a singly linked list where the user first builds the list by entering a specified number of nodes
with their values (added at the end, in the order entered). After the list is built and displayed,
the user enters a position (0-based), and the node at that position is deleted.
If the position is invalid, an appropriate message is displayed and the list remains unchanged.
Display the list before and after this deletion to verify the operation.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the singly linked list
struct node{
    int data;               //value stored in the node
    struct node* next;      //pointer to the next node (NULL for the last node)
};

//Function for deleting the node at a given position (0-based) in the list
struct node* DeleteAtPosition(struct node* head,int pos)    //takes the current head and the position, returns the head of the updated list
{
    //count the nodes of the list, to know which positions are valid
    struct node *count=head;    //separate pointer for counting, so head is not disturbed
    int length=0;               //number of nodes in the list
    int i;                      //loop counter used while walking to the node before the target
    while(count!=NULL)
    {
        length++;   //keeping track of all the position of the LinkList
        count=count->next;      //move to the next node
    }

    //valid positions are 0 to length
    if(pos<0||pos>length)
    {
        printf("The given position is not in our LinkList so our Linklist remains the same\n");
        return head;        //nothing is deleted, so the list stays unchanged
    }
    struct node* ptr=head;      //walk with ptr so head keeps pointing to the first node
    while(i<pos-1)
    {
        ptr=ptr->next;      //keep moving until ptr reaches the node just before the node to delete
        i++;
    }
    struct node* temp=ptr->next;    //remember the node to delete, so it can be freed
    ptr->next=ptr->next->next;      //previous node skips over the node to delete, so the list stays connected
    free(temp);                     //release the memory of the deleted node
    return head;                    //head is unchanged so it returns the updated list
}

//traverses and prints all node values in the list, ending with NULL
void display(struct node* head)
{
    if(head==NULL)
    {
        printf("The LinkList is empty\n");      //our list is empty so no point of traverse
        return ;
    }
    else
    { 
        struct node* ptr=head;      //walk with ptr so head is not disturbed
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;          //move to the next node
        }
        printf("NULL\n");           //marks the end of the list
    }
}
int main()
{
    int n=0,value=0,pos=0;
    struct node* head=NULL;     //head always points to the first node
    struct node* tail=NULL;     //tail tracks the last node for quick end-insertion
    printf("Enter the number of nodes you want in your LinkList : ");
    scanf("%d",&n);

    //Building the initial list by inserting each value at the end
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of the node at index %d : ",i);
        scanf("%d",&value);
        struct node* temp=(struct node*)malloc(sizeof(struct node));    //create and initialize a new node
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;      //List was empty, so this new node becomes the head
            tail=temp;      //It is also the only node, so it becomes the tail too
        }
        else
        {
            tail->next=temp;    //attach the new node right after the current last node
            tail=temp;          //move tail forward, since this new node is now the last one
        }
    }
    printf("Our LinkList before the insertion is : ");
    display(head);              //print the list before deletion
    printf("Enter the position you want to delete from the LinkList : ");
    scanf("%d",&pos);
    printf("Our Linklist after the deletion is : ");
    head=DeleteAtPosition(head,pos);    //head is updated by the returned value
    display(head);              //print the list after deletion
    return 0;
}
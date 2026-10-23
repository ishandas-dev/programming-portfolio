/*Implement a circular singly linked list where the user builds the list by entering a specified number of 
nodes with their values (added at the end, in the order entered).After the list is built and displayed,
the user enters a value to be deleted. The first node holding that value is removed from the list and the
next pointer of the last node must keep pointing back to the head. Display the list before and after
this deletion to verify that the list is still circular.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the circular singly linked list,next of the last node points back to the head
struct node{
    struct node* next;
    int data;
};

//Deletes the first node that holds the given value from the circular list
struct node* DeleteTheValue(struct node* head, int value)   //takes the current head and the value to delete,returns the head of the updated list
{
    if(head==NULL)
    {
        printf("Our list is empty so the given number does not exist\n");
        return NULL;
    }
    struct node* ptr=head;  //walk with ptr so head keeps pointing to the first node
    if(head->data==value)
    {
        if(head->next==head)
        {
            free(head);     //only node in the list,so deleting it leaves the list empty
            return NULL;
        }
        while(ptr->next!=head)
        {
            ptr=ptr->next;  //move to the last node,the one that points back to head
        }
        struct node* temp=head;     //temp is the old first node to be deleted
        head=head->next;            //move head forward,the second node becomes the first
        ptr->next=head;             //last node points to the new head,which keeps the list circular
        free(temp);                 //release the old first node
        return head;
    }
    while(ptr->next!=head&&ptr->next->data!=value)
    {
        ptr=ptr->next;      //stop at the node just before the one holding the value
    }
    if(ptr->next==head)
    {
        printf("The given value does not exist in our circular LinkList\n");    //came back to head without a match
        return head;
    }
    struct node* temp=ptr->next;    //temp is the node to be deleted
    ptr->next=temp->next;           //skip over temp,if temp was the last node this points back to head
    free(temp);             //release the deleted node
    return head;            //head is unchanged,return the updated list
}

//Prints all node values of the circular list starting from the head
void display(struct node* head)     //takes the head of the list,returns nothing
{
    if(head==NULL)
    {
        printf("Our cicular LinkList is empty\n");  //nothing to traverse
        return;
    }
    struct node* ptr=head;  //walk with ptr so head keeps pointing to the first node
    do{
        printf("%d->",ptr->data);
        ptr=ptr->next;      //move to the next node
    }while(ptr!=head);      //do-while is used so the head is printed before the check,the loop ends once ptr comes back to head
    printf("%d\n",head->data);  //print the head again to show that the last node points back to it
}

int main()
{
    int n,value;
    struct node* head=NULL;     //head always points to the first node
    struct node* tail=NULL;     //tail tracks the last node for quick end-insertion
    printf("Enter the number of nodes in our circular Linklist : ");
    scanf("%d",&n);

    //Building the circular list by adding each value at the end
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of the node at index %d : ",i);
        scanf("%d",&value);
        struct node* temp=(struct node*)malloc(sizeof(struct node));    //create a new node
        temp->data=value;   //store the entered value
        temp->next=NULL;    //it will be the last node for now
        if(head==NULL)
        {
            head=temp;      //list was empty, so this node becomes the head
            tail=temp;      //it is also the only node, so it becomes the tail too
        }
        else
        {
            tail->next=temp;    //attach the new node right after the current last node
            tail=temp;          //move tail forward, since this node is now the last one
        }
        tail->next=head;        //last node points back to the head,which keeps the list circular
    }
    printf("Our circular LinkList before deletion is : ");
    display(head);              //Show the list as built, before the deletion
    printf("Enter the value you want to delete from our circular linklist : ");
    scanf("%d",&value);
    head=DeleteTheValue(head,value);    //returns the head of the updated list
    printf("Our circular Linklist after deletion is : ");
    display(head);              //Show the list after deleting the value
    return 0;
}
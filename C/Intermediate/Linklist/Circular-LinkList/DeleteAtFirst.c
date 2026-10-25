/*Implement a circular singly linked list where the user builds the list by entering a specified number of 
nodes with their values (added at the end, in the order entered).After the list is built and displayed,
the first node of the list is deleted and the next pointer of the last node must keep pointing back to
the new head. Display the list before and after this deletion to verify that the list is still circular.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the circular singly linked list,next of the last node points back to the head
struct node{
    struct node* next;
    int data;
};

//Deletes the first node of the circular list
struct node* DeleteAtFirst(struct node* head)   //takes the current head,returns the new head of the updated list
{
    if(head==NULL)
    {
        printf("There is nothing to delete\n");     //nothing to delete from
        return NULL;
    }
    if(head->next==head)
    {
        free(head);     //only node in the list,so deleting it leaves the list empty
        return NULL;
    }
    struct node* ptr=head;  //walk with ptr so head keeps pointing to the first node until the end
    while(ptr->next!=head)
    {
        ptr=ptr->next;      //move to the last node,the one that points back to head
    }
    struct node* temp=ptr->next;    //temp is the old first node to be deleted
    ptr->next=ptr->next->next;      //last node points to the second node,which keeps the list circular
    head=ptr->next;                 //the second node becomes the new head
    free(temp);                     //release the old first node
    return head;                    //return the list without the old first node
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
    printf("Our circular LinkList before Deletion is : ");
    display(head);              //Show the list as built, before the deletion
    head=DeleteAtFirst(head);     //returns the new head of the updated list
    printf("Our circular Linklist after deletion is : ");
    display(head);              //Show the list after deleting the first node
    return 0;
}
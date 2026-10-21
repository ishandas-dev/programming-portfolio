/*Implement a circular singly linked list where the user builds the list by entering a specified number of 
nodes with their values (added at the end, in the order entered).After the list is built and displayed,
the user enters one more value, which is inserted at the beginning (first position) of the list. The next
pointer of the last node must keep pointing back to the new head. Display the list before and after this
insertion to verify that the list is still circular.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the circular singly linked list,next of the last node points back to the head
struct node{
    struct node* next;
    int data;
};

//Inserts a new node with the given value at the beginning of the circular list
struct node* InsertAtFirst(struct node* head, int value)    //takes the current head and the value to insert,returns the new head of the updated list
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;    //store the given value in the new node
    if(head==NULL)
    {
        printf("LinkList is empty\n");
        newnode->next=newnode;  //only node in the list,so it points to itself to stay circular
        return newnode;         //list was empty, so the new node becomes the head
    }
    struct node* ptr=head;  //walk with ptr so head keeps pointing to the first node until the end
    while(ptr->next!=head)
    {
        ptr=ptr->next;      //move to the last node,the one that points back to head
    }
    newnode->next=head;     //new node points forward to the current first node
    ptr->next=newnode;      //last node points to the new node,which keeps the list circular
    return newnode;         //new node is now the first node of the list
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
    printf("Our circular LinkList before insertion is : ");
    display(head);              
    printf("Enter the value you want to insert at first of our circular linklist : ");
    scanf("%d",&value);
    head=InsertAtFirst(head,value);     //returns the new head of the updated list
    printf("Our circular Linklist after insertion is : ");
    display(head);              
    return 0;
}
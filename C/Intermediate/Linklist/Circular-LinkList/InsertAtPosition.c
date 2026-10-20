/*Implement a circular singly linked list where the user builds the list by entering a specified number of
nodes with their values (added at the end, in the order entered).After the list is built and displayed,
the user enters a position (0-based index) and a value, and the value is inserted at that position.
If the position is invalid (less than 0 or greater than the length of the list),the list remains unchanged.
The next pointer of the last node must keep pointing back to the head.Display the list before and after
this insertion to verify that the list is still circular.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the circular singly linked list,next of the last node points back to the head
struct node{
    struct node* next;
    int data;
};

//inserts a new node with the given value at the given position of the circular list
struct node* InsertAtPosition(struct node* head, int value,int pos)    //takes the current head,the value and the position,returns the head of the updated list
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;    //store the given value in the new node
    int length=0;            //counts the number of nodes in the list
    struct node* temp=head;  //walk with temp so head keeps pointing to the first node
    do{
        length++;           //count the current node
        temp=temp->next;    //move to the next node
    }while(temp!=head);     //do-while is used because in a circular list temp starts at head,the loop ends once temp comes back to head
    if(pos<0||pos>length)   //valid positions are 0 to length (length means insertion at the end)
    {
        printf("The given position is invalid so linklist remains the same with no insertion : ");
        free(newnode);      //no insertion happens,so release the unused node to avoid a memory leak
        return head;        //list remains unchanged
    }
    struct node* ptr=head;  //walk with ptr so head keeps pointing to the first node
    if(pos==0)              //insertion at the first position,so the head changes
    {
        while(ptr->next!=head)
        {
            ptr=ptr->next;  //move until ptr is on the last node
        }
        newnode->next=head; //new node points to the old head
        ptr->next=newnode;  //last node points to the new node,which keeps the list circular
        return newnode;     //new node becomes the new head
    }
    int i=0;                //counts the steps ptr has moved
    while(i<pos-1)          //stop when ptr is on the node at index pos-1,which is just before the required position
    {
        ptr=ptr->next;      //move to the next node
        i++;
    }
    newnode->next=ptr->next;   //new node points to the node that was at the required position
    ptr->next=newnode;         //previous node points to the new node
    return head;               //head is unchanged,return the updated list
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
    int n,value,pos;
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
    printf("Enter the position at which you want to insert : ");
    scanf("%d",&pos);
    printf("Enter the value you want to insert at particular position of our circular linklist : ");
    scanf("%d",&value);
    head=InsertAtPosition(head,value,pos);      //returns the head of the updated list,it changes when pos is 0
    printf("Our circular Linklist after insertion is : ");
    display(head);             
    return 0;
}
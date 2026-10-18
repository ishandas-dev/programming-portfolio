/*Implement a circular singly linked list where the user builds the list by entering a specified number 
of nodes with their values (added at the end, in the order entered).The next pointer of the last node points
back to the first node instead of NULL.Traverse the list starting from the head until the head is reached
again, and display the values to verify that the list is circular.*/

#include<stdio.h>
#include<stdlib.h>

//node structure for the circular singly linked list,next of the last node points back to the head
struct node{
    int data;
    struct node* next;
};

//prints all node values of the circular list starting from the head
void traverse(struct node* head)    //takes the head of the list,returns nothing
{
    if(head==NULL)
    {
        printf("Our cicular LinkList is empty\n");      //nothing to traverse
        return;
    }
    struct node* ptr=head;  //walk with ptr so head keeps pointing to the first node
    do{
        printf("%d->",ptr->data);
        ptr=ptr->next;           //move to the next node
    }while(ptr!=head);          //do-while is used so the head is printed before the check,the loop ends once ptr comes back to head
    printf("%d",head->data);    //print the head again to show that the last node points back to it
}

int main()
{
    int n,value;
    struct node* head=NULL;     //head always points to the first node
    struct node* tail=NULL;     //tail tracks the last node for quick end-insertion
    printf("Enter the number of nodes in out circular LinkList : ");
    scanf("%d",&n);

    //building the circular list by adding each value at the end
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
    printf("Our circular LinkList is : ");
    traverse(head);             //Show the circular list starting from the head
    return 0;
}
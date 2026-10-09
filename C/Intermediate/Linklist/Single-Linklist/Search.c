/*Write a C program to create a singly linked list of n nodes by inserting each value at the end of the list.
Take the number of nodes and their values as input from the user.Then accept a value to be searched and traverse the list to find it.
If the value is found, display its index (position starting from 0) in the list, otherwise display a message saying it is not present.
Use a tail pointer so that every insertion at the end takes O(1) time.*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

//Searches the list linearly for the given value and returns the matching node (or NULL if not found)
struct node* Search(struct node* head, int value)
{
    int index=0;             //index keeps track of the position of the node being checked
    struct node* ptr=head;   //ptr walks through the list starting from the first node
    while(ptr!=NULL)
    {
        if(ptr->data==value) //compare the current node's data with the value we are looking for
        {
            printf("The search number %d is found at index %d",value,index);
            return ptr;
        }
        ptr=ptr->next;      //not a match, so move on to the next node
        index++;
    }
    printf("The search number is not present in the LinkList");
    return NULL;
}
int main()
{
    int n=0,value=0;
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
    printf("Enter the value to be searched : ");
    scanf("%d",&value);
    Search(head,value);
    return 0;
}



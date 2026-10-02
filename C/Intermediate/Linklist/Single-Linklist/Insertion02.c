/*Implement a singly linked list built from user input, and perform four insertions on it: at first,
at a given position (0-based), at end, and after a given value. Each operation works on a fresh copy
of the original list, so the operations do not affect each other.
Display the list before and after every insertion, ending with NULL.
(THIS PROGRAM DOES NOT HANDLE ALL THE EDGE CASES)*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node* InsertAtFirst(struct node* head, int value) //Takes the current head and the value to insert,
{
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=value;    //store the given value in the new node
    newnode->next=head;     //new node points to the current first node
    return newnode;         //returning the list with the new node at first
}
struct node* InsertInBetween(struct node* head,int value,int pos)      //takes the current head, the value and the position (0-based), returns the head of the updated list
{
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
struct node* InsertAtEnd(struct node* head,int value)      //takes the current head and the value to insert, returns the head of the updated list
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* ptr=head;     //walk with ptr so head keeps pointing to the first node
    newnode->data=value;      //store the given value in the new node
    newnode->next=NULL;      //the new node will be the last, so nothing comes after it
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;      //keep moving until ptr reaches the last node
    }
    ptr->next=newnode;      //attach the new node after the current last node
    return head;            //head is unchanged so it returns the updated list
}
struct node* InsertAfterValue(struct node* head,int value,int val)      //takes the current head, the value to insert and the value to search for, returns the head of the updated list
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;      //store the given value in the new node
    struct node* ptr=head;    //walk with ptr so head keeps pointing to the first node
    while(ptr->data!=val)
    {
        ptr=ptr->next;      //keep moving until ptr reaches the node that contains val
    }
    newnode->next=ptr->next;    //first connect the new node to the node after ptr, so the rest of the list is not lost
    ptr->next=newnode;          //then connect ptr to the new node
    return head;                //head is unchanged so it returns the updated list
}
//traverses the list starting from the given node and prints all values on one line, ending with NULL
void traversal(struct node* ptr)
{ 
    while(ptr != NULL)
    {
        printf("%d->",ptr->data);    //print the value followed by a space
        ptr=ptr->next;              //move to the next node
    }
    printf("NULL\n");               //marks the end of the list
}
//builds a brand-new copy of the original list, so each operation works on its own list and the original stays untouched
struct node* copyList(struct node* original)
{
    struct node* head=NULL;     //head of the copy
    struct node* tail=NULL;     //tail tracks the last node of the copy
    struct node* ptr=original;  //walk with ptr over the original list
    while(ptr!=NULL)
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node));    //create a new node for every node of the original
        temp->data=ptr->data;   //copy the value
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;  //copy was empty, so this new node becomes the head
            tail=temp;  //it is also the only node, so it becomes the tail too
        }
        else
        {
            tail->next=temp;    //attach the new node right after the current last node of the copy
            tail=temp;          //move tail forward, since this new node is now the last one
        }
        ptr=ptr->next;          //move to the next node of the original
    }
    return head;
}

//frees every node of the list, so the next operation cannot be affected by this one
void freeList(struct node* head)
{
    while(head != NULL)
    {
        struct node* next = head->next;
        free(head);
        head = next;
    }
}
int main()
{
    struct node* head = NULL;       //head of the list used by the current operation (a copy)
    struct node* original = NULL;   //head of the original list entered by the user, never modified
    struct node* tail = NULL;       //tail tracks the last node of the original list
    int n=0,value=0,pos=0,val=0;

    //Taking the original list from the user, it is kept safe and copied for every operation
    printf("Enter the number of nodes in the LinkList : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of the node at index %d : ",i);
        scanf("%d",&value);
        struct node* temp=(struct node*)malloc(sizeof(struct node));     //Create and initialize a new node
        temp->data=value;
        temp->next=NULL;
        if(original==NULL)
        {
            original=temp;  //List was empty, so this new node becomes the head
            tail=temp;      //It is also the only node, so it becomes the tail too
        }
        else
        {
            tail->next=temp;    //attach the new node right after the current last node
            tail=temp;          //move tail forward, since this new node is now the last one
        }
    }

    //Operation 1: insert at first
    printf("\nInsert at first:\n");
    head = copyList(original);
    printf("Before insertion : ");
    traversal(head); //calling traversal function
    printf("Enter the value you want to insert : ");
    scanf("%d",&value);
    head = InsertAtFirst(head, value);   //reassign head!
    printf("After insertion : ");
    traversal(head);
    freeList(head);

    //Operation 2: insert in between (at a given position)
    printf("\nInsert in between:\n");
    head = copyList(original);
    printf("Before insertion : ");
    traversal(head);
    printf("Enter the value you want to insert : ");
    scanf("%d",&value);
    printf("Enter the position at which you want to insert ,starting from 0 : ");
    scanf("%d",&pos);
    head = InsertInBetween(head,value,pos);   //reassign head!
    printf("After insertion : ");
    traversal(head);
    freeList(head);

    //Operation 3: insert at end
    printf("\nInsert at end:\n");
    head = copyList(original);
    printf("Before insertion : ");
    traversal(head);
    printf("Enter the value you want to insert : ");
    scanf("%d",&value);
    head = InsertAtEnd(head,value);   //reassign head!
    printf("After insertion : ");
    traversal(head);
    freeList(head);

    //Operation 4: insert after a given value
    printf("\nInsert after value:\n");
    head = copyList(original);
    printf("Before insertion : ");
    traversal(head);
    printf("Enter the value you want to insert : ");
    scanf("%d",&value);
    printf("Enter the existing value after which you want to insert : ");
    scanf("%d",&val);
    head = InsertAfterValue(head,value,val);   //reassign head!
    printf("After insertion : ");
    traversal(head);
    freeList(head);
    freeList(original);     //release the original list at the end
    return 0;
}
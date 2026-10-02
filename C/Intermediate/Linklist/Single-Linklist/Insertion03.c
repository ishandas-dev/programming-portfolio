/*Implement a Singly Linked List in C that supports the following operations:
  1. Create a linked list by taking 'n' initial node values as input from the user.
  2. Insert a new node at the beginning of the list.
  3. Insert a new node at the end of the list.
  4. Insert a new node immediately after a given existing value in the list.
  5. Insert a new node at a given position in the list.
  6. Display the current contents of the list.
The program should present a menu-driven interface that repeatedly asks the user which insertion 
operation to perform, executes it, displays the updated list, and asks whether the user wants to 
continue or exit.
 Handle edge cases such as:
 - Inserting into an empty list.
 - Inserting after a value that does not exist in the list.
 - Inserting at a position that is out of bounds.*/

#include<stdio.h>
#include<stdlib.h>

//Structure representing a single node of the linked list
struct node
{
    int data;  //value stored in the node
    struct node* next;  //pointer to the next node in the list
};
struct node* head = NULL;  //Global head pointer (always points to the first node of the list)

//Allocates a new node,sets its data, and initializes its next pointer to NULL
struct node* create(int value) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}

//Inserting a new node at first
void InsertAtFirst(int value)
{
    struct node *newnode = create(value);
    newnode->next=head;  //now head (old first node) is newnode's next value
    head=newnode;         //now newnode, which is entered, is the head
    printf("Inserted %d at the beginning\n",value);
}

//Inserting a new node at last
void InsertAtLast(int value)
{
    struct node *newnode = create(value);

    //Case 1: list is empty, new node becomes the head
    if(head==NULL)
    {
        head=newnode;
        return;
    }

    //Case 2: traverse till the last node
    else
    {
        struct node *ptr = head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;   //now ptr's next value is newnode
        newnode->next=NULL;  //now newnode, which is entered, is the last node
    }
}

//Inserts a new node right after the first node whose data equals 'num' 
void InsertAfterValue(int num,int value)
{
    struct node* newnode= create(value);
    struct node* ptr=head;

    // Edge case: empty list
    if(ptr==NULL)
    {
        printf("The linklist is empty\n");
        free(newnode);  //avoid memory leak since node won't be used
        return;
    }

    //Traverse until we find the node with data == num, or reach the end
    while(ptr!=NULL&&ptr->data!=num)
    {
        ptr=ptr->next;
    }

    //Edge case: value 'num' not found in the list
    if(ptr==NULL)
    {
        printf("The given number %d is not found\n",num);
        free(newnode); //avoid memory leak since node won't be used
        return;
    }
    newnode->next = ptr->next;  //now newnode's next value is what used to be ptr's next
    ptr->next = newnode;        //now ptr's next value is newnode
    printf("Inserted %d after the given value\n",value);
}

//Inserts a new node at a given position 'pos'
void InsertAtPosition(int pos,int value)
{
    struct node* newnode= create(value);
    struct node* ptr=head;

    // Edge case: empty list
    if(ptr==NULL)
    {
        printf("The linklist is empty\n");
        return;
    }

     //case 1: inserting at position 1 is the same as InsertAtFirst
    if(pos==1)
    {
        free(newnode);
        InsertAtFirst(value); //discard InsertAtFirst creates its own node
        return;
    }
    int i=1;

    //Traverse to the node just before the desired position
    while(ptr!=NULL&&i<pos-1)
    {
        ptr=ptr->next;
        i++;
    }

    //Edge case: position is out of bounds (list is shorter than pos)
    if(ptr==NULL)
    {
        printf("The given number position %d is out of bound \n",pos);
        free(newnode);
        return;
    }
    newnode->next=ptr->next;  //now newnode's next value is what used to be ptr's next
    ptr->next=newnode;         //now ptr's next value is newnode
    printf("Inserted %d at the given position",value);
}

//Displays all elements of the linked list from head to the last node
void display()
{
    if(head==NULL)   //check if the list is empty
    {
    printf("The list is empty\n");
    return;             //nothing to print, so exit the function
    }
    else
    {
        struct node* ptr=head;       //ptr starts at head, used to walk the list without disturbing head
        printf("Our LinkList is\n");
        while(ptr!=NULL)             //keep going until ptr falls off the end of the list
        {
            printf("%d ",ptr->data);  //print the current node's value
            ptr=ptr->next;            //now ptr moves to point at the next node
        }
    }
    printf("NULL\n");        //marks the end of the list, since last node's next is NULL
}
int main()
{
    int i,value=0,n=0,ch=0,num=0,pos=0,cont=0;

    //Build the initial list by taking 'n' values from the user
    printf("How many nodes do you want in the Linklist\n",n);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the value of the node \n");
        scanf("%d",&value);
        InsertAtLast(value);     //insert 'value' at the end, building the list in input order
    }
    display();      //show the initial list

    //Menu-driven loop for further insertions
    do{
        printf("Below are the operations for insertion , choose as per your choice\n");
        printf("Enter 1 for insertion at first\n");
        printf("Enter 2 for insertion at last\n");
        printf("Enter 3 for insertion after a given value\n");
        printf("Enter 4 for insertion at a given position\n");
        printf("Enter 5 for exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)       //decide which operation to perform based on user's choice
        {
            case 1:
            printf("Enter the value \n");
            scanf("%d",&value);     
            InsertAtFirst(value);   //insert 'value' at the beginning of the list
            break;
            case 2:
            printf("Enter the value \n");
            scanf("%d",&value);
            InsertAtLast(value);    //insert 'value' at the end of the list
            printf("Inserted %d at the last\n",value);
            break;
            case 3:
            printf("Enter the number after which the value is to be inserted\n");
            scanf("%d",&num);               //existing value after which to insert
            printf("Enter the value \n");
            scanf("%d",&value);
            InsertAfterValue(num,value);    //insert 'value' right after the node containing 'num'
            break;
            case 4:
            printf("Enter the position after which the value is to be inserted\n");
            scanf("%d",&pos);               //the index at which we will insert
            printf("Enter the value \n");
            scanf("%d",&value);
            InsertAtPosition(pos,value);    //insert 'value' at position 'pos'
            break;
            case 5:
            printf("Exiting program\n");
            exit(0);                        //terminate the program immediately
            break;
            default:                        //handle any choice outside 1-5
            printf("Invalid input\n");
        }
        display();   //show list after every operation
        printf("Do you want to continue\n(1=YES,0=NO)");
        scanf("%d",&cont);
    } while(cont==1);
    printf("Exiting program\n");
    return 0;
}

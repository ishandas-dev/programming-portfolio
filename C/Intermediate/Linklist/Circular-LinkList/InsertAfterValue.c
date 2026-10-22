/*Implement a circular singly linked list where the user builds the list by entering a specified number of
nodes with their values (added at the end, in the order entered). After the list is built and displayed,
the user enters a value to search for and a new value to insert. The new node must be inserted immediately
after the node containing the searched value. If the searched value is the last node, the new node becomes
the last node and its next pointer must point back to the head. If the searched value is not present in the
list, display "Value not found" and leave the list unchanged. Display the list before and after this
insertion to verify that the list is still circular.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the circular singly linked list,next of the last node points back to the head
struct node{
    struct node* next;
    int data;
};

//Inserts a new node with the given value after the node that contains val
struct node* InsertAfterValue(struct node* head, int value, int val)    //takes the head,the value to insert and the value to search for,returns the head of the updated list
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;    //store the given value in the new node
    struct node* ptr=head;  //walk with ptr so head keeps pointing to the first node
    if(head->data==val)
    {
        newnode->next=head->next;   //new node points to the node that comes after head
        head->next=newnode;         //head points to the new node
        return head;                //head is unchanged,so return it as it is
    }
    do{
        ptr=ptr->next;      //move to the next node
    }while(ptr->next!=head&&ptr->data!=val);    //stop when val is found or when ptr reaches the last node
    if(ptr->data!=val)
    {
        printf("Value not found\n");    //loop ended at the last node without finding val
        free(newnode);                  //free the unused node to avoid a memory leak
        return head;                    //list is left unchanged
    }
    newnode->next=ptr->next;    //new node points to the node that comes after ptr,if ptr is the last node this is head,so the list stays circular
    ptr->next=newnode;          //node containing val points to the new node
    return head;
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
    int n,value,val;
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
    printf("Enter the value after which you want to insert : ");
    scanf("%d",&val);           //the value to search for in the list
    printf("Enter the value you want to insert after the given val of our circular linklist : ");
    scanf("%d",&value);         //the value stored in the new node
    head=InsertAfterValue(head,value,val);  //returns the head of the updated list
    printf("Our circular Linklist after insertion is : ");
    display(head);
    return 0;
}
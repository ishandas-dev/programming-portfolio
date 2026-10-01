/*Implement a singly linked list with the fixed values 7, 10, 25, 29 (in this order) and perform the
following insertion operations on it, one after another, using the value 54 as the new value:
1. Insert at the first position.
2. Insert at position 2 (0-based).
3. Insert at the end (last position).
4. Insert after a given node (the second node, which contains 10).
5. Insert after a given value (after the node containing 25).
Each operation must start from the original list, so no operation affects another.For every operation, 
display the list before and after the insertion in the form "7 10 25 29 NULL" to verify the operation.
If the list is empty or the given value is not found in operation 5, an appropriate message is displayed.
(THIS PROGRAM DOES NOT HANDLE THE EDGE CASES)*/

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
    if(head==NULL)
    {
        return newnode;     //list was empty, so the new node itself becomes the head
    }
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;      //keep moving until ptr reaches the last node
    }
    ptr->next=newnode;      //attach the new node after the current last node
    return head;            //head is unchanged so it returns the updated list
}
struct node* InsertAfterNode(struct node* head,struct node* prev,int value)      //takes the current head, the node after which to insert and the value, returns the head of the updated list
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;        //store the given value in the new node
    newnode->next=prev->next;   //first connect the new node to the node after prev, so the rest of the list is not lost
    prev->next=newnode;         //then connect prev to the new node
    return head;                //head is unchanged so it returns the updated list
}
struct node* InsertAfterValue(struct node* head,int value,int val)      //takes the current head, the value to insert and the value to search for, returns the head of the updated list
{
    if (head==NULL)
    {
        printf("The LinkList is empty\n");      //nothing to search in, so no insertion is possible
        return head;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;      //store the given value in the new node
    struct node* ptr=head;    //walk with ptr so head keeps pointing to the first node
    while(ptr->data!=val&&ptr->next!=NULL)
    {
        ptr=ptr->next;      //keep moving until ptr reaches the node with val, or the last node
    }
    if(ptr->data!=val)
    {
        printf("The given value is not found\n");   //reached the last node and it is not val either
        free(newnode);                              //value not found, so release the unused node
        return head;
    }
    newnode->next=ptr->next;    //first connect the new node to the node after ptr, so the rest of the list is not lost
    ptr->next=newnode;          //then connect ptr to the new node
    return head; 
}
//traverses the list starting from the given node and prints all values on one line, ending with NULL
void traversal(struct node* ptr)
{ 
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);    //print the value followed by a space
        ptr=ptr->next;              //move to the next node
    }
    printf("NULL\n");               //marks the end of the list
}
//builds a fresh list 7 -> 10 -> 25 -> 29 every time it is called, so each operation starts from the same original list
struct node* createList()
{
    // allocating memory for 4 nodes
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    struct node* fourth=(struct node*)malloc(sizeof(struct node));

    //linking node 1
    head->data=7;
    head->next=second;

    //linking node 2
    second->data=10;
    second->next=third;

    //linking node 3
    third->data=25;
    third->next=fourth;

    //last node points to null to mark the end 
    fourth->data=29;
    fourth->next=NULL;
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
    struct node* head = NULL;

    //Operation 1: insert at first
    printf("Insert at first : ");
    head=createList();
    printf("Before insertion : ");
    traversal(head); //calling traversal function
    head=InsertAtFirst(head,54);   //reassign head!
    printf("After insertion : ");
    traversal(head);
    freeList(head);

    //Operation 2: insert in between (at position 2)
    printf("\nInsert in between (position 2) : \n");
    head=createList();
    printf("Before insertion : ");
    traversal(head);
    head=InsertInBetween(head,54,2);   //reassign head
    printf("After insertion : ");
    traversal(head);
    freeList(head);

    //Operation 3: insert at end
    printf("\nInsert at end : \n");
    head=createList();
    printf("Before insertion : ");
    traversal(head);
    head=InsertAtEnd(head,54);   //reassign head!
    printf("After insertion:  ");
    traversal(head);
    freeList(head);

    //Operation 4: insert after a given node (the second node)
    printf("\nInsert after node : \n");
    head = createList();
    printf("Before insertion : ");
    traversal(head);
    head=InsertAfterNode(head,head->next,54);   //head->next is the second node
    printf("After insertion : ");
    traversal(head);
    freeList(head);

    //Operation 5: insert after a given value (after 25)
    printf("\nInsert after value 25\n");
    head=createList();
    printf("Before insertion : ");
    traversal(head);
    head=InsertAfterValue(head,54,25);   //reassign head!
    printf("After insertion : ");
    traversal(head);
    freeList(head);
    return 0;
}
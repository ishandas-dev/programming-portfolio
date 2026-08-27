/*Create a singly linked list of 4 nodes manually (without a loop),linking each node to the next 
using malloc, and write a function to traverse the list and print all the elements.*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};

//traverses the list starting from the given node and prints each element
void traversal(struct node* ptr)
{ 
    while(ptr != NULL)
    {
        printf("element is: %d \n",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    // allocating memory for 4 nodes
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));

    //linking node 1
    head->data=7;
    head->next=second;

    //linling node 2
    second->data=10;
    second->next=third;

    //linking node 3
    third->data=25;
    third->next=fourth;

    //last node points to null to mark the end 
    fourth->data=29;
    fourth->next=NULL;

    traversal(head); //calling traversal function
    return 0;
}


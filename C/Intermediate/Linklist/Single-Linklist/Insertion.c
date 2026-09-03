#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node* InsertAtFirst(struct node* head, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node*));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct node* InsertInBetween(struct node* head,int data,int index)
{
    struct node*ptr = (struct node*)malloc(sizeof(struct node*));
    struct node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct node* InsertAtEnd(struct node*head,int data)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node*));
    ptr->data=data;
    struct node* p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct node* InsertAfterNode(struct node*head,struct node*prevnode,int data)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node*));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}

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
    
    printf("Before insertion:\n");
    traversal(head); //calling traversal function
    /*head = InsertAtFirst(head, 54);   // reassign head!
    printf("After insertion:\n");
    traversal(head);*/
    /*head = InsertInBetween(head,54,2);   // reassign head!
    printf("After insertion:\n");
    traversal(head);*/
    /*head = InsertAtEnd(head,54);   // reassign head!
    printf("After insertion:\n");
    traversal(head);*/
    head = InsertAfterNode(head,second,54);   // reassign head!
    printf("After insertion:\n");
    traversal(head);
    return 0;
}


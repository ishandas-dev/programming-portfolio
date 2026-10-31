/*Implement a linear queue using a linked list.The user can enqueue, dequeue, check empty, 
check full, peek and display from a menu.Enqueue adds a node at the rear and dequeue removes the node at the front.*/

#include<stdio.h>
#include<stdlib.h>

//Node structure for the singly linked list used by the queue
struct node{
    struct node* next;      //pointer to the next node (NULL for the last node)
    int data;               //value stored in the node
};
struct node* front=NULL;    //front points to the first node, where deletion happens
struct node* rear=NULL;     //rear points to the last node, where insertion happens

//Function to check whether the queue is empty, returns 1 if empty otherwise 0
int is_empty()
{
    return front==NULL;     //front is NULL only when there are no nodes in the queue
}

//Function to check whether the queue is full, it tries to allocate one node and returns 1 if memory is not available otherwise 0
int is_full()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));    //try to allocate one trial node
    if(temp==NULL)          //malloc returns NULL when no memory is available
    {
        return 1;           //memory is exhausted, so the queue is full
    }
    free(temp);             //allocation worked, so give the trial node back to avoid a memory leak
    return 0;               //there is still space, so the queue is not full
}

//Function to insert the value x at the rear of the queue
void enqueue(int x)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));     //create a new node
    if(newnode==NULL)       //check whether the node was created
    {
        printf("Queue overflow\n");     //no memory, so the node cannot be created
        return;                         //stop the function without inserting
    }
    newnode->data=x;        //store the value in the new node
    newnode->next=NULL;     //it will be the last node, so next is NULL
    if(is_empty())          //check whether this is the first node of the queue
    {
        front=newnode;      //queue was empty, so this node becomes the front
        rear=newnode;       //it is also the only node, so it becomes the rear too
    }
    else
    {
        rear->next=newnode;     //attach the new node after the current last node
        rear=newnode;           //move rear forward, since the new node is now the last one
    }
    printf("Enqueued %d \n",x);     //confirm the insertion to the user
}

//Function to remove the front node of the queue and return its value, returns -1 if the queue is empty
int dequeue()
{
    if(is_empty())          //check whether there is anything to remove
    {
        printf("Underflow\n");      //nothing to remove from an empty queue
        return -1;                  //-1 is used as the error value
    }
    struct node* temp=front;    //remember the first node so it can be freed
    int x=front->data;          //save its value so it can be returned
    front=front->next;          //second node becomes the new front
    if(front==NULL)             //check whether the removed node was the only node
    {
        rear=NULL;              //the queue is now empty, so rear must be reset too
    }
    free(temp);                 //release the memory of the removed node
    return x;                   //return the removed value
}

//Function to return the front value without removing it, returns -1 if the queue is empty
int peek()
{
    if(is_empty())          //check whether there is anything to look at
    {
        printf("Underflow\n");      //nothing to look at if the queue is empty
        return -1;                  //-1 is used as the error value
    }
    return front->data;     //value of the first node
}

//Function to traverse and print all values of the queue from front to rear
void display()
{
    struct node* temp=front;    //walk with temp so front is not disturbed
    if(is_empty())              //check whether the queue has any nodes
    {
        printf("Queue is empty\n");     //no nodes, so there is nothing to traverse
    }
    while(temp!=NULL)           //run until the end so the rear node is printed too
    {
        printf("%d ",temp->data);   //print the value of the current node
        temp=temp->next;            //move to the next node
    }
    printf("\n");               //move to a new line after printing all values
}

//Main function that shows the menu and calls the queue functions according to the user's choice
int main()
{
    int con=0;      //stores whether the user wants to continue (1 = yes, 0 = no)
    int ch=0;       //stores the menu choice
    int x;          //stores the value to insert or the value returned by dequeue and peek
    do{
        printf("Enter the following numbers for following functions : \n");    //menu heading
        printf("Enter 1. for Enqueue\n");
        printf("Enter 2. for Dequeue\n");
        printf("Enter 3. for empty\n");
        printf("Enter 4. for full\n");
        printf("Enter 5. for peek\n");
        printf("Enter 6. for display\n");
        printf("Enter 7 for exiting the program\n");
        scanf("%d",&ch);        //read the user's menu choice
        switch(ch)              //run the function that matches the user's choice
        {
            case 1:                 //insert a value
            printf("Enter the value of x : ");
            scanf("%d",&x);         //read the value to insert
            enqueue(x);             //add the value at the rear
            break;
            case 2:                 //remove a value
            x=dequeue();            //remove the front value and store it in x
            if(x!=-1)               //-1 means the queue was empty
            {
                printf("dequeued : %d\n",x);    //print only if dequeue succeeded
            }
            break;
            case 3:                 //check whether the queue is empty
            if(is_empty())
            {
                printf("Queue is empty\n");         //is_empty returned 1
            }
            else
            {
                printf("Queue is not empty\n");     //is_empty returned 0
            }
            break;
            case 4:                 //check whether the queue is full
            if(is_full())
            {
                printf("Queue is full\n");          //is_full returned 1
            }
            else
            {
                printf("Queue is not full\n");      //is_full returned 0
            }
            break;
            case 5:                 //show the front element
            x=peek();               //get the front value without removing it
            if(x!=-1)               //-1 means the queue was empty
            {
                printf("peek : %d\n",x);        //print only if peek succeeded
            }
            break;
            case 6:                 //show all elements
            display();              //print the whole queue
            break;
            case 7:                 //end the program immediately
            printf("Existing from program\n");
            exit(0);                //terminate the program
            break;
            default:                //any other number is not a valid option
            printf("Invalid choice , please choose again\n");
        }
        printf("Do you want to continue? if yes then select 1 otherwise 0 : ");
        scanf("%d",&con);       //read whether the user wants another operation
    }while(con==1);             //repeat the menu only if the user entered 1
    return 0;                   //program ended successfully
}
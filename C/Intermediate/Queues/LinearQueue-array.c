/*Implement a linear queue using an array.The user can enqueue, dequeue, check empty, check full,
peek and display from a menu.Enqueue adds an element at the rear and dequeue removes the element at the front.*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10     //maximum number of elements the queue can hold
int queue[SIZE];    //array that stores the queue elements
int front=-1;       //index of the first element, -1 means the queue is empty
int rear=-1;        //index of the last element, -1 means the queue is empty

//Function to check whether the queue is full, returns 1 if full otherwise 0
int is_full()
{
    return rear==SIZE-1;    //the last valid index is SIZE-1, so rear there means no space is left
}

//Function to check whether the queue is empty, returns 1 if empty otherwise 0
int is_empty()
{
    return front==-1;       //front stays -1 until the first element is added
}

//Function to insert the value x at the rear of the queue
void enqueue(int x)
{
    if(is_full())           //check whether there is space for a new element
    {
        printf("Queue is overflow\n");  //no space left in the array
        return;                         //stop the function without inserting
    }
    if(is_empty())          //check whether this is the first element
    {
        front=0;            //front starts pointing to index 0 on the first insertion
    }
    rear++;                 //move rear to the next free position
    queue[rear]=x;          //store the value at the rear
    printf("Enqueued %d\n",x);      //confirm the insertion to the user
}

//Function to remove the front element of the queue and return its value, returns -1 if the queue is empty
int dequeue()
{
    if(is_empty())          //check whether there is anything to remove
    {
        printf("Underflow\n");      //nothing to remove from an empty queue
        return -1;                  //-1 is used as the error value
    }
    int x=queue[front];     //save the front element so it can be returned
    if(rear==front)         //front and rear are equal when only one element is left
    {
        front=-1;           //queue becomes empty, so reset front
        rear=-1;            //queue becomes empty, so reset rear
    }
    else
    {
        front++;            //otherwise move front to the next element
    }
    return x;               //return the removed value
}

//Function to return the front value without removing it, returns -1 if the queue is empty
int peek()
{
    if(is_empty())          //check whether there is anything to look at
    {
        printf("Queue is underflow\n");     //nothing to look at if the queue is empty
        return -1;                          //-1 is used as the error value
    }
    return queue[front];    //value at the front of the queue
}

//Function to print all elements of the queue from front to rear
void display()
{
    if(is_empty())          //check whether the queue has any elements
    {
        printf("Queue is underflow\n");     //nothing to print if the queue is empty
        return ;                            //stop the function
    }
    for(int i=front;i<=rear;i++)    //go from front to rear, including rear
    {
        printf("%d ",queue[i]);     //print the element at index i
    }
    printf("\n");           //move to a new line after printing all elements
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
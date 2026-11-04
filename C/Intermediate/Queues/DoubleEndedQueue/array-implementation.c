/*Implement a double ended queue(deque) of fixed size using a circular array.The user can insert and delete
elements from both the front and the rear,peek at the front and rear elements,and display the deque.
Front and rear wrap around the end of the array so that no space is wasted.Handle the overflow and 
underflow cases and provide a menu driven program to test all the operations.*/

#include<stdio.h>
#define SIZE 10     //maximum number of elements the deque can hold
int dequeue[SIZE];  //array that stores the elements of the deque
int front=-1;       //index of the first element,-1 means the deque is empty
int rear=-1;        //index of the last element,-1 means the deque is empty

//Checks whether the deque has no elements
int is_empty()      //returns 1 if empty,otherwise 0
{
    return front==-1;
}

//Checks whether the deque has no free space left
int is_full()       //returns 1 if full,otherwise 0
{
    return (front==0&&rear==SIZE-1||front==rear+1);     //full when rear is at the last index with front at 0,or when rear is right behind front after wrapping
}

//Inserts an element at the front of the deque
void insert_front(int x)    //takes the value to insert,returns nothing
{
    if (is_full())
    {
        printf("Queue overflow\n");     //no free space to insert
        return;
    }
    if(is_empty())
    {
        front=0;    //first element,so both front and rear point to index 0
        rear=0;
    }
    else if(front==0)
    {
        front=SIZE-1;   //front is at the start of the array,so it wraps around to the last index
    }
    else
    {
        front--;        //move front one step backward to make room
    }
    dequeue[front]=x;   //store the value at the new front
    printf("%d inserted",x);
}

//Inserts an element at the rear of the deque
void insert_rear(int x)     //takes the value to insert,returns nothing
{
    if(is_full())
    {
        printf("dequeue overflow\n");   //no free space to insert
        return;
    }
    if(is_empty())
    {
        front=0;    //first element,so both front and rear point to index 0
        rear=0;
    }
    else if(rear==SIZE-1)
    {
        rear=0;     //rear is at the end of the array,so it wraps around to index 0
    }
    else
    {
        rear++;     //move rear one step forward to make room
    }
    dequeue[rear]=x;    //store the value at the new rear
    printf("%d inserted",x);
}

//Deletes the element at the front of the deque
int delete_front()  //returns the deleted value,or -1 if the deque is empty
{
    int x;
    if(is_empty())
    {
        printf("Queue Underflow\n");    //nothing to delete
        return -1;
    }
    x=dequeue[front];   //save the value before front moves away from it
    if(rear==front)
    {
        front=-1;   //only one element was present,so the deque becomes empty
        rear=-1;
    }
    else if(front==SIZE-1)
    {
        front=0;    //front is at the end of the array,so it wraps around to index 0
    }
    else
    {
        front++;    //move front one step forward
    }
    return x;
}

//Deletes the element at the rear of the deque
int delete_rear()   //returns the deleted value,or -1 if the deque is empty
{
    int x;
    if(is_empty())
    {
        printf("Underflow\n");  //nothing to delete
        return -1;
    }
    x=dequeue[rear];    //save the value before rear moves away from it
    if(rear==front)
    {
        front=-1;   //only one element was present,so the deque becomes empty
        rear=-1;
    }
    else if(rear==0)
    {
        rear=SIZE-1;    //rear is at the start of the array,so it wraps around to the last index
    }
    else
    {
        rear--;     //move rear one step backward
    }
    return x;
}

//Returns the front element without removing it
int peek_front()    //returns the front value,or -1 if the deque is empty
{
    if(is_empty())
    {
        printf("dequeue is empty\n");   //no front element to show
        return -1;
    }
    return dequeue[front];
}

//Returns the rear element without removing it
int peek_rear()     //returns the rear value,or -1 if the deque is empty
{
    if(is_empty())
    {
        printf("dequeue is empty\n");   //no rear element to show
        return -1;
    }
    return dequeue[rear];
}

//Prints all elements of the deque from front to rear
void display()
{
    if(is_empty())
    {
        printf("dequeue is empty\n");   //nothing to print
        return;
    }
    int i=front;    //start from the front element
    while(i!=rear)
    {
        printf("%d ",dequeue[i]);
        i=(i+1)%SIZE;   //move forward and wrap around to index 0 after the last index
    }
    printf("%d ",dequeue[rear]);    //the loop stops at rear,so print the rear element separately
}
int main()
{
    int choice,x;
    while(1)    //keep showing the menu until the user chooses to exit
    {
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Peek Front");
        printf("\n6. Peek Rear");
        printf("\n7. Display");
        printf("\n8. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter value: ");
            scanf("%d",&x);
            insert_front(x);    //insert the entered value at the front
            break;
            case 2:
            printf("Enter value: ");
            scanf("%d",&x);
            insert_rear(x);     //insert the entered value at the rear
            break;
            case 3:
            x=delete_front();
            if(x!=-1)
            {
                printf("Deleted from front: %d\n",x);   //print only if a value was actually deleted
            }
            break;
            case 4:
            x=delete_rear();
            if(x!=-1)
            {
                printf("Deleted from rear: %d\n",x);    //print only if a value was actually deleted
            }
            break;
            case 5:
            x=peek_front();
            if(x!=-1)
            {
                printf("Front element: %d\n",x);        //print only if the deque is not empty
            }
            break;
            case 6:
            x=peek_rear();
            if(x!=-1)
            {
                printf("Rear element: %d\n",x);         //print only if the deque is not empty
            }
            break;
            case 7:
            display();
            break;
            case 8:
            return 0;   //exit the program
            default:
            printf("Invalid choice\n");     //choice was not between 1 and 8
        }
    }
}
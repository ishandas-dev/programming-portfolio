/*Question: Understand how pointers work in C — declaring a pointer, dereferencing it, and the
difference between a pointer's value, its dereferenced value, and its own address.*/

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the value of the number \n");
    scanf("%d",&n);
    int* ptr=&n;                    //ptr stores the address of n
    int* ptr2=ptr;                  //ptr2 copies ptr's value, so it also points to n
    int** ptr3 = &ptr;              //ptr3 stores the address of ptr itself (pointer to a pointer)
    printf("%d \n",n);              //value of n
    printf("%p \n",ptr);            //address stored in ptr (same as &n)
    printf("%d \n",*ptr);           //dereferencing ptr gives back n's value
    printf("%p \n",&ptr);           //address of ptr itself, not of n
    printf("%d \n",*ptr2);          //ptr2 points to the same n, so same value
    printf("%p \n",&ptr2);          //address of ptr2 — different from &ptr
    printf("%p \n",ptr2);           //value in ptr2 (same address as ptr, &n)
    printf("%p \n",*&ptr2);         //& and * cancel out, same as printing ptr2
    printf("%p \n", ptr3);          //value in ptr3 = address of ptr (same as &ptr)
    printf("%p \n", *ptr3);         //dereference once: get ptr's value = &n
    printf("%d \n", **ptr3);        //dereference twice: get n's value
    printf("%p \n", &ptr3);         //address of ptr3 itself (a third, distinct location)
    return 0;
}
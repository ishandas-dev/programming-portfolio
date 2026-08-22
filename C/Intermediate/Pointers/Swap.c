#include<stdio.h>
void swap(int* ptr1,int* ptr2)
{
    int temp;
    temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;

}
int main()
{
int a,b;
printf("Enter the values of both the pointers \n");
scanf("%d%d",&a,&b);
printf("The value of a before swap is %d \nThe value of b before swap is %d",a,b);
swap(&a,&b);
printf("\nThe value of a after swap is %d \nThe value of b after swap is %d",a,b);
return 0;
}
/*Student Record Management — Highest Marks Finder
Write a C program that:
Takes the number of students n as input
For each student, reads: name, gender, marks and roll number using a structure
Displays all student records
Finds and displays the record of the student with the highest marks*/

#include<stdio.h>
//Structure to hold a single student's record
typedef struct
{
    int roll_no;
    char name[50];
    char gen;
    float marks;
}student;
int main()
{
    int n,i;

    //Get number of students
    printf("Enter the number of students \n");
    scanf("%d",&n);

    student s[n];  //array of structures

    //Input loop - read details for each student
    for(i=0;i<n;i++)
    {
        printf("Enter the name\n");
        scanf(" %[^\n]",s[i].name);   //%[^\n] reads full line including spaces
        printf("Enter the gender\n");
        scanf(" %c",&s[i].gen);       //leading space skips leftover newline
        printf("Enter the marks\n");
        scanf(" %f",&s[i].marks);
        printf("Enter the roll no \n");
        scanf(" %d",&s[i].roll_no);
    }

    //printing all student records
    for(i=0;i<n;i++)
    {
        printf("name is %s\n",s[i].name);
        printf("gender is %c\n",s[i].gen);
        printf("roll no is %d\n",s[i].roll_no);
        printf("marks is %f\n",s[i].marks);
    }

    //Find index of student with highest marks
    int max=0;
    for(i=0;i<n;i++)
    {
        if(s[i].marks>s[max].marks)
        max=i;
    }
    printf("person with the highest marks is \n");
    printf("name is %s\n",s[max].name);
    printf("gender is %c\n",s[max].gen);
    printf("roll no is %d\n",s[max].roll_no);
    printf("marks is %f\n",s[max].marks);
    return 0;
}

/*Write a program to read an integer and print it's multiplication table in java*/

import java.util.*;
public class Multiplication
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int num=0,i,mul=1,n;
        System.out.println("Enter the number till which the table should be printed");
        n=in.nextInt();
        System.out.println("Enter the number to be multipled");
        num=in.nextInt();
        System.out.println("The multiplication table of the given number"+num);
    
        //using loop to print multiplication table
        for(i=0;i<=n;i++)  
        {
           mul=i*num; 
           System.out.println(+i + "*" +num +"=" +mul);
        }
}
}
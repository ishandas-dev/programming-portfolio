/* To check the given number is even or odd using java
(Even numbers are integers exactly divisible by 2 (ending in 0, 2, 4, 6, or 8), 
while odd numbers are integers not divisible by 2 (ending in 1, 3, 5, 7, or 9)*/

import java.util.*;
public class Evenodd
{
    public static void main (String args[])
    {
        Scanner in = new Scanner(System.in);
        int n;
        System.out.println("Enter the value of number ");
        n=in.nextInt();
        if(n%2==0) //checking if the number is divisible by 2 or not
        System.out.println("The given number is even number \n"+n);
        else
        System.out.println("The given number is odd number \n"+n);
    }
}
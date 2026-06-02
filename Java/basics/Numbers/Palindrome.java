/* To check the given number is palindrome number or not using java (A palindromic number is a number
 that remains the same when its digits are reversed, reading the same forwards and backwards.)
 Example of palindrome number are: 121,3443 */

import java.util.*;
public class Palindrome
{
     public static void main(String args[])
     {
        Scanner in = new Scanner(System.in);
        int n,rev=0,digit=0,temp=0;
        System.out.println("Enter the number");
        n=in.nextInt();
        temp=n; //storing value of the number in temp variable

        //using while loop to reverse the given number
        while(temp>0) 
        {
            digit= temp%10;  //extracting the last digit of the number
            rev=(rev*10)+digit; //reversing the number
            temp=temp/10; //removing the last digit
        }
        if(n==rev)
        System.out.println("The given number is a palindrome number "+n);
        else
        System.out.println("The given number is not a palindrome number "+n);
     }

}
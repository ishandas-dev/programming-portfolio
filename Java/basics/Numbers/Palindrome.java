import java.util.*;
public class Palindrome
{
     public static void main(String args[])
     {
        Scanner in = new Scanner(System.in);
        int n,rev=0,digit=0,temp=0;
        System.out.println("Enter the number");
        n=in.nextInt();
        temp=n;
        while(temp>0)
        {
            digit= temp%10;
            rev=(rev*10)+digit;
            temp=temp/10;
        }
        if(n==rev)
        System.out.println("The given number is a palindrome number "+n);
        else
        System.out.println("The given number is not a palindrome number "+n);
     }

}
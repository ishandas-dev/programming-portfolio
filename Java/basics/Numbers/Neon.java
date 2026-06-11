/*To check the given number is Neon number or not using C (A neon number is a special integer where 
the sum of the digits of its square equals the original number.)
Example of neon number is: 9 as 9^2 = 81 and 8+1=9.*/

import java.util.*;
public class Neon
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int n,square,temp=0,digit=0,sum=0;
        System.out.println("Enter the value of number ");
        n=in.nextInt();
        square=n*n;
        temp=square; //using temporary variable to store the square of the given number

        //storing the sum of the digits of the square of given number
        while(temp>0)
        {
            digit=temp%10;
            sum=sum+digit;
            temp=temp/10;
        }
        if(sum==n)
        System.out.println("The given number is a neon number as it's square's digits sum is itself "+n);
        else
        System.out.println("The given number is not a neon number as it's square's digits sum is not equal "+n);
    }
}


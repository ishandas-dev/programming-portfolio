/* To check the given number is prime or composite number using C (Prime numbers are natural numbers
 greater than 1 with exactly two factors (1 and themselves), 
 Example of prime numbers are: 2, 3, 5, and 7. 
 while Composite numbers are natural numbers greater than 1 with more than two factors
 Example of Composite numbers are: 4, 6, 8, and 9. 
The number 1 is considered neither prime nor composite.)*/

import java.util.*;
public class Prime
{
    public static void main(String args[])
    {
        Scanner in= new Scanner(System.in);
        int n,i,count=0;   
        System.out.println("Enter the value of number");
        n=in.nextInt();

        //counting that from how many digits the number is divisible
        for(i=1;i<=n;i++)
        {
            if(n%i==0)
            count++;
        }
        if(count==2)
        System.out.println("the given number is prime \n"+n);
        else if(count!=2)
        System.out.println("the given number is composite number \n"+n);
        else
        System.out.println("The given number is 1 which is neither prime nor composite \n");
    }
}
 

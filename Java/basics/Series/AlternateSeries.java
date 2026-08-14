/*An alternating series is an infinite series where the signs of the terms continually flip back and
forth between positive and negative like sum of (1-2+3-4+5-6...till n)*/

import java.util.*;
public class AlternateSeries
{
    public static void main(String args[])
    {
        Scanner in= new Scanner(System.in);
        int n,i,sum=0;
        System.out.println("Enter the value of n");
        n=in.nextInt();
        System.out.println("The series looks like this :");
        for(i=1;i<=n;i++)
        {
            if(i==1) 
            {
                System.out.print(" "+i); //printing the first number of the series
                sum=sum+i;
            }
            else if(i%2==0)   //checking for even and odd
            {
                System.out.print(" - "+i); //printing the series
                sum=sum-i; //calculating the sum
            }
            else
            {
                System.out.print(" + "+i); //printing the series
                sum=sum+i;        //calculating the sum
            }
        }
        System.out.println("\nThe sum of Alternate series for given number is "+sum);
    }
}

    
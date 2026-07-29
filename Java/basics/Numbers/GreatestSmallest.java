/*Checking the greatest and smallest number using C++*/

import java.util.*;
public class GreatestSmallest
{
    public static void main (String args[])
    {
        Scanner in = new Scanner(System.in);
        int a,b;
        System.out.println("Enter the value of a and b respectively");
        a=in.nextInt();
        b=in.nextInt();
        if(a>b)
        {
            System.out.println("The greatest number is a whose value is "+a);
            System.out.println("The smallest number is b whose value is "+b);
        }
        else
        {
            System.out.println("The greatest number is b whose value is "+b);
            System.out.println("The smallest number is a whose value is "+a);
        }
    }
}

/*A square number series is a mathematical sequence where each term is the product of an 
integer multiplied by itself, expressed as (n^2).
The sequence begins (1, 4, 9, 16, 25, 36, 49, 64, 81, 100 till n)*/

import java.util.*;
public class SquareSeries
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int num,i,square=0;
        System.out.println ("Enter the value till which the series to be printed");
        num=in.nextInt();
        //using loop for squaring the numbers
        for(i=1;i<=num;i++)
        {
            if(i==1)
            {
                square=i*i;     //squaring the starting number
                System.out.println(+square); //printing the square
                square=0;      //initializing the variable to 0 so we can use it again
            }
            else
            {
                square= i*i;       //squaring the numbers
                System.out.println(+square); //printing the square
                square=0;          //again initializing the variable to 0 so we can use it again
            }
        }
    }
}
//you might wonder why i am squaring 1 separately , its because i want to print "," too after each number
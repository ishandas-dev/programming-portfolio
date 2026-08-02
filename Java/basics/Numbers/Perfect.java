
/*To check the given number is perfect number or not using java (A perfect number is a positive integer
 equal to the sum of its proper positive divisors (excluding the number itself))
Example of perfect number are : 6 (divisors: 1, 2, 3 and 1+2+3=6) 
                                28 (divisors: 1, 2, 4, 7, 14 and 1+2+4+7+14=28)  */
 
import java.util.*;
public class Perfect
{
    public static void main(String args[])
    {
        Scanner in= new Scanner(System.in);
        int num,i,sum=0;
        System.out.println("Enter the value of number ");
        num=in.nextInt();

        //to store the sum of all the numbers which are divisble to the given number
        for(i=1;i<num;i++)
         {
            if(num%i==0)
            sum=sum+i;
         }
        if(sum==num)
        System.out.println("The given Number %d is perfect number "+num);
        else
        System.out.println("The given Number %d is not a perfect number "+num);
    }
}
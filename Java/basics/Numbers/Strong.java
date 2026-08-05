/*To check the given number is strong number or not in Java (A Strong number is a special number in 
mathematics and computer science where the sum of the factorials of its digit equals the original number
Example of strong number are: 145 as 1!+4!+5! = 145 itself )*/

import java.util.*;
public class Strong
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int num,fact=1,i,temp=0,digit=0,sum=0;
        System.out.println("Enter the value of number");
        num=in.nextInt();
        temp=num; //using a temporary variable for storing our given value

        //finding out the sum of the factorials of its digits 
        while(temp>0)
        {
            digit=temp%10; //extracting the last digit of the number
            for(i=1;i<=digit;i++)
            {
                fact=fact*i;//Storing the factorial of the digit
            }
            sum=sum+fact; //storing the sum of all the digits factorial
            fact=1;       //initializing fact as 1 so we can use it again for another digit
            temp=temp/10; //removing the last digit
        }
    if(num==sum)
    System.out.println("The given number "+num + " is a strong number as it's sum of its digit's factorial is also "+sum);
    else
    System.out.println("The given number "+num + " is not a strong number as it's sum of its digit's factorial is different "+sum);
    }
}
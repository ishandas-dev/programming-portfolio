/*To check the given number is spy number or not in java(A Spy number is a positive integer where the
sum of its digits equals the product of its digits.)
Example of spy number are: 1124 as 1+1+2+4=8 and 1*1*2*4=8*/

import java.util.*;
public class Spy
{
    public static void main (String args[])
    {
        Scanner in = new Scanner(System.in);
        int sum=0,pro=1,digit=0,temp=0,num;
        System.out.println("Enter the value of number");
        num=in.nextInt();
        temp=num;     //using the temporary variable to store the number

        //calculating the sum and product of digits present in the number
        while(temp>0)
        {
            digit=temp%10; //extracting the last digit of the number
            sum=sum+digit; //storing the sum of all digits
            pro=pro*digit; //storing the product of all digits
            temp=temp/10;  //removing the last digit
        }
    if(sum==pro)
    System.out.println("The given number "+num + " is a spy number as its sum "+sum + " and its product "+pro + " is same");
    else
    System.out.println("The given number "+num + " is not a spy number as its sum "+sum + " and its product "+pro + " is different");
    }
}

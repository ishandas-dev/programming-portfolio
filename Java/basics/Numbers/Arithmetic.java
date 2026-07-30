/*Program of using basic arithmetic operators using c*/

import java.util.*;
public class Arithmetic
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);

         //variables to store inputs and results of each operation
         float a,b,add=0.0f,sub=0.0f,mul=0.0f,div=0.0f;
        System.out.println("Enter the value of a and b");
        a=in.nextFloat();
        b=in.nextFloat();

        //performing all four operations
        add=a+b;
        sub=a-b;
        mul=a*b;
        div=a/b;
        System.out.println("The sum of a and b is \n"+add);
        System.out.println("The difference of a and b is \n"+sub);
        System.out.println("The product of a and b is \n"+mul);
        System.out.println("The quotient of a and b is %f \n"+div);
    }
}
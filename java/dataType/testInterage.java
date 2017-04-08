/*************************************************************************
	> File Name: testInterage.java
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Aug 2016 09:47:06 PM CST
 ************************************************************************/

public class testInterage{
    public static void main(String[] args){

        System.out.println(Integer.MAX_VALUE);
        System.out.println(Integer.MIN_VALUE);


        int a = Integer.parseInt("1234");
        System.out.println("a = " + a);

        String binString = Integer.toBinaryString(10);
        System.out.println("10 = " + binString);

        String strA = Integer.toString(10);
        System.out.println("10 = " + strA);
    }
}


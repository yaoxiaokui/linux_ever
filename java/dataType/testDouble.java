/*************************************************************************
	> File Name: testDouble.java
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Aug 2016 09:53:36 PM CST
 ************************************************************************/

public class testDouble{
    public static void main(String[] args){

        System.out.println("Double max = " + Double.MAX_VALUE);
        System.out.println("Double min = " + Double.MIN_VALUE);

        double d = Double.parseDouble("123.456");
        System.out.println(d);

        String strD = Double.toString(d);
        System.out.println(strD);

    }
}


/*************************************************************************
	> File Name: testObject.java
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Aug 2016 10:08:50 PM CST
 ************************************************************************/

public class testObject{

    public static void main(String[] args){
        Object o1 = new Object();
        Object o2 = new Object();

        System.out.println("o1 == o2  : " + o1 == o2);
        
        System.out.println(o1.hashCode());
        System.out.println(o2.hashCode());

        System.out.println(o1.toString());
        System.out.println(o2.toString());

        System.out.println("---------------------------------");

        Student s1  = new Student("linux", 12, 1);
        Student s2  = new Student("ever", 12, 1);
        Student s3  = new Student("linux_ever", 12, 1);

        System.out.println(s1.toString());
        System.out.println(s2.toString());
        System.out.println(s3.toString());


    }
}

class Student implements Cloneable{
    private String name;
    private int age;
    private int sex;

    public Student(String name, int age, int sex){
        this.name = name;
        this.age = age;
        this.sex = sex;
    }

    public String toString(){
        //System.out.println("name: " + name + ", age = " + age + ", sex = " + sex);
        return "name: " + name + ", age = " + age + ", sex = " + sex;
    }

    /*
    public void clone(){
        ///return super.clone();
        super.clone();

    }
    */
}


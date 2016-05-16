/*************************************************************************
	> File Name: shape.java
	> Author: 
	> Mail: 
	> Created Time: Mon 16 May 2016 03:29:08 PM CST
 ************************************************************************/
package pa;

public class shape
{
    public static void main(String [] args){
        Circle c1 = new Circle();
        c1.draw();

        Rectange r1 = new Rectange();
        r1.draw();

        Shape s1 = new Circle();
        s1.draw();
        Shape s2 = new Rectange();
        s2.draw();

        System.out.println("Person draw: ");
        Person p = new Person();
        p.drawShape(c1);
        p.drawShape(r1);
        //p.drawShape(s1);
        //p.drawShape(s2);
        //
        Shape s3 = p.getCircleShape();
        s3.draw();
    }
}

class Person
{
    void drawShape(Shape shape){
        shape.draw();
    }

    Shape getCircleShape(){
        return new Circle();
    }
}

//基类
class Shape
{
    void draw(){
        System.out.println("Shape.draw()...");
    }

}

//圆类
class Circle extends Shape
{
    void draw(){
        System.out.println("Circle.draw()...");
    }
}

//矩形类
class Rectange extends Shape
{
    void draw(){
        System.out.println("Rectange.draw()...");
    }
}

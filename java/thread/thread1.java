/*************************************************************************
	> File Name: thread1.java
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Aug 2016 07:22:01 PM CST
 ************************************************************************/

public class thread1{
    public static void main(String[] args){
        MyThread1 Thread1 = new MyThread1();
        Thread1.start();

        for(int i = 0; i < 10; ++i){
            try{
                Thread.sleep(1000);
            }
            catch(Exception e){
                e.printStackTrace();
            }

            System.out.println("main run");
        }

    }
}

class MyThread1 extends Thread{
    public void run(){
        for(int i = 0; i < 10; ++i){
            try{
                Thread.sleep(1000);
            }
            catch(Exception e){
                e.printStackTrace();
            }

            System.out.println("MyThread1 run");
        }
    }
}




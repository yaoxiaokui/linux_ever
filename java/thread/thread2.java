/*************************************************************************
	> File Name: thread1.java
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Aug 2016 07:22:01 PM CST
 ************************************************************************/

public class thread2{
    public static void main(String[] args){
        MyThread2 Thread2 = new MyThread2();

        Thread thread2 = new Thread(Thread2);
        thread2.start();

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

class MyThread2 implements Runnable{
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


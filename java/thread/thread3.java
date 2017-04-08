/*************************************************************************
	> File Name: thread1.java
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Aug 2016 07:22:01 PM CST
 ************************************************************************/

public class thread3{
    public static void main(String[] args){
        MyThread3 myThread3 = new MyThread3();
        MyThread4 myThread4 = new MyThread4();

        //创建线程1
        Thread thread3 = new Thread(myThread3);

        //创建线程2
        Thread thread4 = new Thread(myThread4);

        System.out.println("thread3 priority = " + thread3.getPriority());
        System.out.println("thread4 priority = " + thread4.getPriority());

        thread3.setPriority(Thread.MIN_PRIORITY);
        thread4.setPriority(Thread.MAX_PRIORITY);
        //thread4.setPriority(Thread.MAX_PRIORITY);

        System.out.println("thread3 priority = " + thread3.getPriority());
        System.out.println("thread4 priority = " + thread4.getPriority());

        thread3.start();
        thread4.start();

        for(int i = 0; i < 10; ++i){
            /*
            try{
                Thread.sleep(1000);
            }
            catch(Exception e){
                e.printStackTrace();
            }

            */
            System.out.println("main run");
        }

    }
}

class MyThread3 implements Runnable{
    public void run(){
        for(int i = 0; i < 10; ++i){
            /*
            try{
                Thread.sleep(1000);
            }
            catch(Exception e){
                e.printStackTrace();
            }
            */

            System.out.println("MyThread3 run");
        }
    }
}

class MyThread4 implements Runnable{
    public void run(){
        for(int i = 0; i < 10; ++i){
            /*
            try{
                Thread.sleep(1000);
            }
            catch(Exception e){
                e.printStackTrace();
            }
            */

            System.out.println("MyThread4 run");
        }
    }
}

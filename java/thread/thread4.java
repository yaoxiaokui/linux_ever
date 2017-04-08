/*************************************************************************
	> File Name: thread1.java
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Aug 2016 07:22:01 PM CST
 ************************************************************************/

public class thread4{
    public static void main(String[] args){
        MyThread5 myThread5 = new MyThread5();
        MyThread6 myThread6 = new MyThread6();

        //创建线程1
        Thread thread3 = new Thread(myThread5);

        //创建线程2
        Thread thread4 = new Thread(myThread6);

        System.out.println("thread3 priority = " + thread3.getPriority());
        System.out.println("thread4 priority = " + thread4.getPriority());

        //thread3.setPriority(Thread.MIN_PRIORITY);
        //thread4.setPriority(Thread.MAX_PRIORITY);

        System.out.println("thread3 priority = " + thread3.getPriority());
        System.out.println("thread4 priority = " + thread4.getPriority());

        thread3.start();
        thread4.start();

        for(int i = 0; i < 100; ++i){
            /*
            try{
                Thread.sleep(1000);
            }
            catch(Exception e){
                e.printStackTrace();
            }

            */
            System.out.print("m");
            Thread.yield();
        }

    }
}

class MyThread6 implements Runnable{
    public void run(){
        for(int i = 0; i < 100; ++i){
            /*
            try{
                Thread.sleep(1000);
            }
            catch(Exception e){
                e.printStackTrace();
            }
            */

            System.out.print("6");
            Thread.yield();
        }
    }
}

class MyThread5 implements Runnable{
    public void run(){
        for(int i = 0; i < 100; ++i){
            /*
            try{
                Thread.sleep(1000);
            }
            catch(Exception e){
                e.printStackTrace();
            }
            */

            System.out.print("5");
            Thread.yield();
        }
    }
}

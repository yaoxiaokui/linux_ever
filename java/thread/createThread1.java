/*************************************************************************
	> File Name: createThread1.java
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Jun 2016 09:11:45 PM CST
 ************************************************************************/

import java.lang.Thread;
import java.lang.Exception;

public class createThread1
{
    public static void main(String[] args){

        new Thread1().start();

        for(int i = 0; i < 5; ++i){
            try{
                Thread.sleep(1000);
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }

            System.out.println("main run...");
        }
    }
}

class Thread1 extends Thread
{
    public void run(){
        for(int i = 0; i < 5; ++i){
            try{
                Thread.sleep(1000);
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }

            System.out.println("Thread1 run...");
        }
    }
}

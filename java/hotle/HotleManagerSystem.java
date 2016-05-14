/*************************************************************************
	> File Name: HotleManagerSystem.java
	> Author: 
	> Mail: 
	> Created Time: 2016年05月14日 星期六 15时32分57秒
 ************************************************************************/

import java.util.Scanner;
public class HotleManagerSystem
{
    public static void main(String [] args){
        //12层楼，每层10个房间
        //0101 0102 0103...
        //0201 0202 0203...
        //0301 0302 0303...
        //................
        //1201 1202 1203...

        String [][]rooms = new String[12][10];

        System.out.println("欢迎来到酒店!");
        System.out.print("请输入命令，执行操作：");
        System.out.println("init:初始化; search:查询；in:办理入住；out:办理退房；quit:退出");

        Scanner s = new Scanner(System.in);
        String command; 
        
        while(true){
            System.out.print("请输入操作命令: ");

            command = s.next();
            if(command.equals("quit")){
                break;
            }
            else if(command.equals("init")){
                init(rooms);
            }
            else if(command.equals("in")){
                in(rooms);
            }
            else if(command.equals("out")){
                out(rooms);
            }
            else if(command.equals("search")){
                search(rooms);
            }
            else{
                System.out.println("输入命令错误，请重新输入!");
            }
        }

    }    

    //办理入住手续
    public static void in(String [][]rooms){

        System.out.println("下面是空的房间:");
        printEmptyRooms(rooms);

        System.out.print("请输入房间号: ");
        Scanner s = new Scanner(System.in);

        while(true){
            int roomNum = s.nextInt();

            int floor = roomNum / 100;//楼层
            int num = roomNum % 100;//房间号

            if(floor < 0 || floor > 12 || num < 0 || num > 10){
                System.out.println("房间号输错了，请继续输入: ");
            }
            else if(rooms[floor-1][num-1] == null){
                System.out.print("请输入入住人姓名: ");
                String name = s.next();
                rooms[floor-1][num-1] = name; 
                System.out.println("办理入住完毕!");
                return;
            }
            else{
                System.out.print("房间已经有人入住，请继续输入: ");
            }
        }
    }

    //办理退房
    public static void out(String [][]rooms){
        while(true){

            System.out.print("输入房间号办理退房: ");
            Scanner s = new Scanner(System.in);
            int roomNum = s.nextInt();
            System.out.print("请输入入住人姓名: ");
            String name = s.next();
        
            int floor = roomNum / 100;//楼层号
            int num = roomNum % 100;//房间号

            if(floor < 0 || floor > 12 || num < 0 || num > 10){
                System.out.print("房间号输错了，请继续输入: ");
            }
            else if(rooms[floor-1][num-1].equals(name)){
                rooms[floor-1][num-1] = null;    
                System.out.println("退房成功!");
                return;
            }
            else{
                System.out.println("姓名输入错误，请重新输入!");
            }
        }
    }

    //打印空的房间
    public static void printEmptyRooms(String [][]rooms){
        for(int i = 0; i < rooms.length; ++i){
            //打印房间号
            for(int j = 0; j < rooms[i].length; ++j){
                if(rooms[i][j] == null){
                    if(i <= 8){
                        System.out.print('0');
                    }
                    int roomNum = (i+1)*100 + j + 1;
                    System.out.print(roomNum + "\t");
                }
            }
            System.out.println();
            //打印房间状态
            for(int k = 0; k < rooms[i].length; ++k){
                if(rooms[i][k] == null)
                    System.out.print(rooms[i][k] + "\t");
            }
            System.out.println();
            System.out.println();
        }
        
    }

    //初始化房间状态为空
    public static void init(String [][]rooms){
        for(int i = 0; i < rooms.length; ++i){
            for(int j = 0; j < rooms[i].length; ++j){
                rooms[i][j] = null;
            }
        }
        System.out.println("房间初始化完毕!");
    }

    //查询所有房间状态
    public static void search(String [][]rooms){
        for(int i = 0; i < rooms.length; ++i){
            //打印房间号
            for(int j = 0; j < rooms[i].length; ++j){
                if(i <= 8){
                    System.out.print('0');
                }
                int roomNum = (i+1)*100 + j + 1;
                System.out.print(roomNum + "\t");
            }
            System.out.println();
            //打印房间状态
            for(int k = 0; k < rooms[i].length; ++k){
                System.out.print(rooms[i][k] + "\t");
            }
            System.out.println();
            System.out.println();
        }
        
    }
}

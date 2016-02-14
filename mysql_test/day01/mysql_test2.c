/*************************************************************************
	> File Name:mysql_test.c 
	> Author: 
	> Mail: 
	> Created Time: 2016年02月11日 星期四 10时45分31秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

char database_name[1024];
char table_name[1024];
char query[1024];


int main(int argc, char *argv[])
{

    if(argc <= 2){
        printf("input: %s database_name table_name\n", argv[0]);
        return -1;
    }

    strcpy(database_name, argv[1]);
    strcpy(table_name, argv[2]);

    int ret = 0;
    
    MYSQL mysql;
    MYSQL * connect = NULL;
    connect = mysql_init(&mysql);
    if(connect == NULL){
        ret = mysql_errno(&mysql);
        printf("mysql_init error, %s\n", mysql_error(&mysql));
        return ret;
    }
    printf("mysql_init ok...\n");


    connect = mysql_real_connect(connect, "localhost", "root", "yxk", database_name, 0, NULL, 0);
    if(connect == NULL){
        ret = mysql_errno(&mysql);
        printf("mysql_real_connect error, err is: %s\n", mysql_error(&mysql));
        return ret;
    }
    printf("mysql_real_connect ok...\n");

    //设置查询字符集属性为utf8
    ret = mysql_query(&mysql, "set names utf8");
    if(ret != 0){
        printf("mysql_query error\n");
        return ret;
    }

    //查询数据
    strcpy(query, "select * from ");
    strcat(query, table_name);
    ret = mysql_query(connect, query);
    if(ret != 0){
        printf("mysql_query error\n");
        return ret;
    }

    MYSQL_RES *result = mysql_store_result(&mysql);
    if(result == NULL){
        printf("mysql_store_result error\n");
        return -1;
    }
    
    int field_num = mysql_field_count(&mysql);
    //表头
    MYSQL_FIELD * fields = mysql_fetch_fields(result);
    int i = 0;

    printf("-------------------------------------------------------------\n");
    for(i= 0; i < field_num; i++){
        printf("%s \t", fields[i].name); 
    }
    printf("\n---------------------------------------------------------------\n");


    //表内容
    MYSQL_ROW row = NULL;
    while(row = mysql_fetch_row(result)){
        for(i= 0; i < field_num; i++){
            printf("%s \t", row[i]); 
        }
        printf("\n");
    }

    mysql_free_result(result);//释放内存

    mysql_close(connect);

    printf("mysql_close...\n");

    return ret;
}



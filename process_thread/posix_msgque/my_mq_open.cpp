/*************************************************************************
	> File Name: my_mq_open.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月08日 星期二 20时11分16秒
 ************************************************************************/

#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

using namespace std;

int main(int argc, char* argv[])
{
    mqd_t mqd = mq_open("/abcd", O_CREAT | O_RDONLY, 0666, NULL);
    if(mqd == -1){
        cout << "mq_open error\n";
        return -1;
    }

    cout << "mq_open success, mqd = " << mqd << endl;
    mq_close(mqd);
    mq_unlink("/abcd");
    cout << "mq_close success\n";

    return 0;
}


/*************************************************************************
	> File Name: inputToOutput.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Jul 2016 09:09:35 AM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>


const int BUFFER_SIZE = 1024;

int main()
{
    char buffer[BUFFER_SIZE];

    int n = 0;
    while((n = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0){
        write(STDOUT_FILENO, buffer, n);
    }


    return 0;
}

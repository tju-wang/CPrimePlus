#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/*
CPrimerPlus  Chaper13
Q2.实现文件拷贝程序 从命令行读取文件名

 */

//argv[0]  内容是本main函数科执行文件的绝对路径
//argv[...]  其余内容是  命令行输入的字符串  以空格作为分隔符 
int main(int argc, char *argv[])
{

    printf("%d  \n",argc);
    if(argc != 3)
    {
        printf("Please input two files name.\n");
    }
    else
    {
        puts(argv[1]);
        printf("2. \n");
        puts(argv[2]);
    }
    
    return 0;
}


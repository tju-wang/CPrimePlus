#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"


extern void test_13_2(int argv, char *argc[]);
extern void test_13_7(int argc, char *argv[]);
extern void test_13_8(int argc, char *argv[]);
extern void test_13_10(int argc, char *argv[]);
extern void test_13_14(int argc, char *argv[]);



/*
CPrimerPlus  Chaper13
Q2.实现文件拷贝程序 从命令行读取文件名
*powershell 输入命令行的文件名只能是绝对路径  相对路径读取方式有待尝试
powershell下  输入：  将 code_13_2.c文件拷贝至 file1.txt
.\test.exe D:\CProgram\CPrimerPlus\Chapter_13\code_13_2.c D:\CProgram\CPrimerPlus\Chapter_13\flie1.txt


 */

//argv[0]  内容是本main函数科执行文件的绝对路径
//argv[...]  其余内容是  命令行输入的字符串  以空格作为分隔符 
int main(int argc, char *argv[])
{

    // test_13_2(argc,argv);
    // test_13_7(argc,argv);
    // test_13_8(argc,argv);
    // test_13_10(argc,argv);
    test_13_14(argc,argv);
    return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"


extern void test_14_1(int argv, char *argc[]);
extern void test_14_2(int argv, char *argc[]);
extern void test_14_5(int argv, char *argc[]);
extern void test_14_8(int argv, char *argc[]);

/*
CPrimerPlus  Chaper14  结构和其他数据形式

 */

//argv[0]  内容是本main函数科执行文件的绝对路径
//argv[...]  其余内容是  命令行输入的字符串  以空格作为分隔符 
int main(int argc, char *argv[])
{

    // test_14_1(argc,argv);
    // test_14_2(argc,argv);
    // test_14_5(argc,argv);
    test_14_8(argc,argv);
    return 0;
}


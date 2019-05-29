#include <stdio.h>
#include <string.h>

/*
C PrimerPlus
定义指针数组  调用各个题目的测试函数

Chapter11--Q6
test_11_6()
在替换处  添加对 空格 制表符的替换  替换为\0  表示读取结束
// *strlen()函数  参数是接受到的数组时  不能正确返回长度
// *!!很奇怪的问题  检测不到第一个字符。。。
Chapter11-8


*/

char * s_gets(char *st,int n);


extern void test_11_6(void);
extern void test_11_8(void);
extern void test_11_11(void);

int main (int argc,char *argv[])
{
    //test_11_6();
    // test_11_8();
    test_11_11();
    return 0;
}
/*自定义字符串读取函数  
注意 函数不适用于读取单个字符
原因是fgets函数 在字符串末尾自动添加"\n"  此时会被函数替换为"\0"
 */

char * s_gets(char *st,int n)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(st,n,stdin);

    if(ret_val)
    {
        while (st[i] != '\n' && st[i] !='\0')
            i++;
        if(st[i]=='\n')     //替换换行符  为‘\0’
            st[i] = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
            
        
    }
    return ret_val;
}




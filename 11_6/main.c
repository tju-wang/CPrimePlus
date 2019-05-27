#include <stdio.h>
#include <string.h>

/*
C PrimerPlus
Chapter11--Q2
在替换处  添加对 空格 制表符的替换  替换为\0  表示读取结束
// *strlen()函数  参数是接受到的数组时  不能正确返回长度
// *!!很奇怪的问题  检测不到第一个字符。。。

*/

char * s_gets(char *st,int n);
char iswithin(char ch,char *str,int len);

int main (int argc,char *argv[])
{
    char mchar[80];
    char charfind[1];
    char result;

    printf("input string you want:\n");
    s_gets(mchar,80);


    
    printf("%d\n",strlen(mchar));
    int mcharlen = strlen(mchar);

    printf("input char you want find:\n");
    scanf("%c",charfind);

    if(iswithin(charfind[0],mchar,mcharlen))
    {
        printf("find the char in this string");
    }
    else
    {
        printf("the char can't find in this string");
    }
    
    return 0;
}
/*自定义字符串读取函数  
注意 函数不适用于读取单个字符
原因是fgets函数 在字符串末尾自动添加"\n"  此时会被函数替换为"\0"
 */

char * s_gets(char *st,int n)
{
    char * ret_val;
    int i = 1;
    ret_val = fgets(st,n,stdin);

    if(ret_val)
    {
        while (st[i] != '\n' && st[i] !='\0')
            i++;
        if(st[i]=='\n')     //替换换行符  为‘\0’
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
        
    }
    return ret_val;
}

char iswithin(char ch,char *str,int len)    // 找出字符串中是否有该字符 有 返回1  无 返回0
{
    char ret = 0;
    int i;

    for (i=0;i<len;i++)
    {
        if(str[i]==ch)
        {
            ret = 1;
            break;
        }
    }

    return ret;
}


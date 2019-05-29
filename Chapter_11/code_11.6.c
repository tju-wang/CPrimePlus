#include <stdio.h>
#include <string.h>

extern char * s_gets(char *st,int n);

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

void test_11_6(void)
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

}


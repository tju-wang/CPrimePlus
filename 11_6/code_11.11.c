#include <stdio.h>
#include <string.h>
/*Chapter11-Q11
1.字符串输入函数
2.菜单循环显示函数
3.5个功能实现函数
4.测试函数代码

 */

#define STR_NUMBER  10

extern char iswithin(char ch,char *str,int len) ;
extern char * s_gets(char *st,int n);

void input_string(char **str,int *len)
{
    int i = 0;
    for(i=0; i<STR_NUMBER; i++)
    {
        s_gets((*str)+i,20);    //读入字符串
        if(**str == EOF)
        {
            break;
        }
        len = i+1;
    }
}

void disp_menu(char **str,int len)
{
    int choose;

    while (1)
    {
        printf("1.print the original string.\n");
        printf("2.print the string in alphabetic order.\n");
        printf("3.print the string in length order.\n");
        printf("4.print the string in the legth of first word order.\n");
        printf("5.Quit this menu.\n");
        
        printf("what you want to do?\n");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:{
                ori_order();
            }break;
            case 2:{
                alph_order();
            }break;
            case 3:{
                len_order();
            }break;
            case 4:{
                first_wordlen_order();
            }break;
            case 'q':
            case 'Q':
            case 5:{
                pro_quit();
            }break;
            default:{
                printf("please press the number again.\n");
            }
        }

    }
    

}

void test_11.11(void)
{
    char m_str[11][20];
    int str_len = 0;
    printf("please input some string:\n");
    input_string(m_str,&str_len);

    disp_menu(m_str,str_len);
}

//各函数的实现
void ori_order(char **str,int len)
{
    for(int i=0;i<len;i++)
    {
        puts((*str)+i);
    }
}

void alph_order(char **str,int len)
{
    // char *firstAlph;
    // firstAlph = malloc(sizeof(long int)*len);   //存 len 个char的数组
    // char *temp;
    // temp = malloc(sizeof(long int));
    // *firstAlph = *str;
    long int firstAlph[11];
    long int temp;

    firstAlph[0] = *str;

    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            if(*firstAlph[j] > *(*str+i))
            {
                *temp = (*str+i);
                (*str+i) = *firstAlph;
                *firstAlph =  *temp;
            }
        }
    }
    ori_order(str,len);

}

void len_order(char **str,int len)  //按照字符串长度输出
{
    int str_len[11];
    int 
    for(int i=0;i<len;i++)
    {
        str_len[i] = strlen(*str+i);
    }
    //排序部分 需要带着之前的序号排序
    

}






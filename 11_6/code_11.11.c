#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Chapter11-Q11
1.字符串输入函数
2.菜单循环显示函数
3.5个功能实现函数
4.测试函数代码

总结：
1.输入函数  需要修改后才能符合题目  需要测试 --》找了很久的bug出现在输入函数  变量i初值为1 
输入函数第一个字符为回车换行  不被替换为 '\0'  导致之后的很多问题
2.存在编译器优化情况   定义变量而未赋值，调用函数 使用传地址方式传入定义的参数  而且之后也没有 该变量在等号左边
    则，无论是数组  指针（malloc申请空间） 还是直接定义变量  都会被编译器优化
3.多个功能  处理一组数据  先要保证数据不被某一个功能改变  本次的写法很不好
本例题中，可以定义存储字符串地址的指针数组  实现各种排序  也不用一直纠结怎么保持元数据


 */

#define STR_NUMBER  10
#define LENGTH  255

extern char iswithin(char ch,char *str,int len) ;
extern char * s_gets(char *st,int n);
void maxValueSort(int *data,int len,int *sort);    //找出数组中的最大值的序号
void len_order(char (*str)[LENGTH],int len);  //按照字符串长度输出
void int_printf(int *arr,int len);


void ori_order(char (*str)[LENGTH],int len);
void alph_order(char (*str)[LENGTH],int len);
void first_words_len_order(char (*str)[LENGTH],int len);


void input_string(char (*str)[LENGTH] ,int *len)
{
    int i = 0;
    for(i=0; i<STR_NUMBER; i++)
    {
        s_gets(str[i],LENGTH);    //读入字符串
        if(str[i][0]=='\0')
        {
            break;
        }
        *len = i+1;
    }
}

void disp_menu(char (*str)[LENGTH],int len)
{
    int choose;

    while (1)
    {
        printf("1.print the original string.\n");
        printf("2.print the string in alphabetic order.\n");
        printf("3.print the string in length order.\n");
        printf("4.print the string in the legth of first word order.\n");
        printf("5.Quit this menu.\n");
        
        printf("what do you want to do?\n");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:{
                printf("the original string.\n");
                ori_order(str,len);
            }break;
            case 2:{
                printf("the string in alphabetic order.\n");
                alph_order(str,len);
            }break;
            case 3:{
                printf("the string in length order.\n");
                len_order(str,len);
            }break;
            case 4:{
                 printf("the string in the legth of first word order.\n");
                first_words_len_order(str,len);
            }break;
            case 'q':
            case 'Q':
            case 5:{
                exit(0);
            }break;
            default:{
                printf("please press the number again.\n");
            }
        }

    }
    

}

void swap_arr(char *str1,char *str2,int len)     //交换两个地址的内容
{
    char *temp = malloc(sizeof(char));

    for(int i=0;i<len;i++)
    {
        *temp = *(str1+i);
        *(str1+i) = *(str2+i);
        *(str2+i) = *temp;
    }
}

void test_11_11(void)
{
    char m_str[11][LENGTH];
    int str_len = 0;
    printf("please input some string:\n");
    input_string(m_str,&str_len);

    // printf("1 %d  %d \n",strlen(&m_str[0][0]),strlen(&m_str[1][0]));
    disp_menu(m_str,str_len);
}

//各函数的实现
void ori_order(char (*str)[LENGTH],int len)
{
    for(int i=0;i<len;i++)
    {
        puts(*((str)+i));
    }
}



void alph_order(char (*str)[LENGTH],int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            if(str[i][0]>str[j][0])
            {
                swap_arr(&str[i][0],&str[j][0],LENGTH);
            }
        }
    }
    ori_order(str,len);

}



void maxValueSort(int *data,int len,int *sort)    //找出数组中的最大值的序号
{
    int max = *data;
    for(int i=0; i<len; i++)
    {
        if(max<*(data+i))
        {
            *sort = i;
            max = *(data+i);
        }
           
    }
    // printf("%d \n",*sort);

}

void len_order(char (*str)[LENGTH],int len)  //按照字符串长度输出
{
    static int str_len[11];
    static int order[11];
    // int *t_order = malloc(sizeof(int));
    // *t_order = 0;
    static int t_order; //此处 若不用static修斯  则必须给t_order赋初值   不赋初值 会被智障编译器优化！！指针在malloc内存之后也要赋初值！！
    int max;
    int sort;
    int len_temp = len;
    for(int i=0;i<len;i++)
    {
        str_len[i] = strlen(*(str+i));
    }
    
    //排序部分 需要带着之前的序号排序
    for(int sort=0; sort<len; sort++)    
    {
        maxValueSort(str_len,len_temp,&order[sort]);
        //找出最大值后  处理数值     删掉order[i]处的值
        str_len[order[sort]] = 0;
    }
    //order[]数组中  存放了 len 个按照 值大小 排列的序号值 按照order的内容  输出对应的字符串
    for(int j=0;j<len;j++)
    {   
        puts(*(str+order[j]));
    }
}

void int_printf(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int first_word_length(char *str,int len)   //检测字符串第一个单词的长度  并返回
{
    int ret = 0;
    for(ret=0; ret<len; ret++)
    {
        if(*(str+ret)==' ')
            break;
    }

    return ret;
}


void first_words_len_order(char (*str)[LENGTH],int len)  //按照字符串长度输出
{
    static int str_len[11];
    static int order[11];
    // int *t_order = malloc(sizeof(int));
    // *t_order = 0;
    static int t_order; //此处 若不用static修斯  则必须给t_order赋初值   不赋初值 会被智障编译器优化！！指针在malloc内存之后也要赋初值！！
    int max;
    int sort;
    int len_temp = len;
    for(int i=0;i<len;i++)
    {
        str_len[i] = first_word_length((char *)str[i],strlen(*(str+i)));
    }
    
    //排序部分 需要带着之前的序号排序
    for(int sort=0; sort<len; sort++)    
    {
        maxValueSort(str_len,len_temp,&order[sort]);
        //找出最大值后  处理数值     删掉order[i]处的值
        str_len[order[sort]] = 0;
    }
    //order[]数组中  存放了 len 个按照 值大小 排列的序号值 按照order的内容  输出对应的字符串
    for(int j=0;j<len;j++)
    {   
        puts(*(str+order[j]));
    }
}






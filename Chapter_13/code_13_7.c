#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXIT_1  1
#define EXIT_2  2

/*
*比较奇怪  函数库的strcat函数  第二个字符串内容会覆盖第一个字符串的内容

//**自己写字符串拼接函数

 */
char strcat_m(char *dest,char *str);
void constring(char s[],char t[], char q[]);

void test_13_7(int argc, char *argv[])
{
    int count = 0;
    if(argc != 3)
    {
        printf("Please input two files name.\n");
    }
    // else
    // {
    //     puts(argv[1]);
    //     printf("2. \n");
    //     puts(argv[2]);
    // }
    
    //打开文件  获取原始文件名  拷贝文件名
    FILE *fp_1,*fp_2;
    char ch;
    if((fp_1 = fopen(argv[1],"rb")) == NULL)
    {
        printf("Can't open %s\n",argv[1]);
        exit(EXIT_1);
    }
    if((fp_2 = fopen(argv[2],"rb")) == NULL)
    {
        printf("Can't open %s\n",argv[2]);
        exit(EXIT_2);
    }
    char *praw1 = NULL;
    char *praw2 = NULL;
    praw1 = malloc(sizeof(char)*1024);
    praw2 = malloc(sizeof(char)*1024);
    int raw1Counter,raw2Counter,Counter;
    Counter = 0;
    char flag = 1;
    char flagOver1,flagOver2;
    flagOver1 = 1;   flagOver2 = 1;
    int i = 0;
    while(flagOver1 || flagOver2)
    {
        Counter++;
        flag = 1;  i=0;

        while( (flag && flagOver1) )    
        {
            i++;
            if( (ch = getc(fp_1)) == '\n' )     {
                flag = 0;
                *(praw1+i-1) = ch;
                raw1Counter++;
            }
            else if (ch == EOF)
            {
                flagOver1 = 0;
            }
            else       {
                *(praw1+i-1) = ch;
            }
        }
        *(praw1+i-1) = '\0';
        flag = 1;  i=0;

        while(flag&&flagOver2)    
        {
            i++;
            if( (ch = getc(fp_2)) == '\n' )     {
                flag = 0;
                *(praw2+i-1) = ch;
                raw2Counter++;
            }
            else if (ch == EOF)
            {
                flagOver2 = 0;
            }
            else       {
                *(praw2+i-1) = ch;
           }
        }
        *(praw2+i-1) = '\0';

        //a.  两个文件 轮番输出
        // if(raw1Counter == Counter)  //假设在文件最后一行  仍然会有换行符存在
        //     puts(praw1);
        // if(raw2Counter == Counter)
        //     puts(praw2);
        
        //b.两个文件的相同行号的文件合并
        if(raw1Counter == Counter && raw2Counter == Counter)    {   //假设在文件最后一行  仍然会有换行符存在  
            //连接两个字符串
            // puts(praw1);
            // printf("%d \n",strlen(praw1));
            // puts(praw2);
            // printf("%d \n",strlen(praw2));
            

            strcat(praw1,praw2);
            // constring((praw1),(praw2+1),praw1);
            puts(praw1);

            //直接连接字符串  不行  会导致  行计数都出错
            // int len = strlen(praw1);
            // for(int k=0; k<strlen(praw2);k++)
            // {
            //     *(praw1 + len -1 + k) = *(praw2+k); 
            // }
            // puts(praw1);
        }
        else if (raw1Counter != Counter && raw2Counter == Counter)
        {
            puts(praw2);
        }
        else if (raw1Counter == Counter && raw2Counter != Counter)
        {
            puts(praw1);
        }
        else
        {
            break;
        }
        

    }

    printf("the file 1 is %d raws.\n",raw1Counter);
    printf("the file 2 is %d raws.\n",raw2Counter);
    printf("the file is %d raws.\n",Counter);
    

    fclose(fp_1);
    fclose(fp_2);
    free(praw1);
    free(praw2);

    
}

//有问题！！
char strcat_m(char *dest,char *str)
{
    int len = strlen(str);
    int dest_len = strlen(dest);
    printf("%d  %d\n",dest_len,len);

    for(int i=0 ; i<len; i++)
    {
        *(dest + dest_len -1 + i) = *(str + i );
    }

    return 1;
}


void constring(char s[],char t[], char q[])          
{
    int i, j;
    for (i = 0; s[i] != '\0'; i++)
    {
        q[i] = s[i];
    }
    for (j = 0; t[j] != '\0'; j++)
    {
        q[i + j] = t[j];
    }
    q[i + j] = '\0';
}



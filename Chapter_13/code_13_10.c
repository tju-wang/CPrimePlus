#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define EXIT_1  1
#define EXIT_2  2

char * s_gets(char *st,int n);

void test_13_10(int argc, char *argv[])
{
    static int count = 0;
    
    printf("Please insert a file name.\n");
    char *fname = malloc(sizeof(char)*1024);
    
    s_gets(fname,1024);     //输入绝对路径
    if(strlen(fname)<=1)
    {
        printf("The insert name is too short.");
        return ;
    }

    //打开文件  获取原始文件名  拷贝文件名
    FILE *fp;

    char ch;
    if((fp = fopen(fname,"r")) == NULL)
    {
        printf("Can't open %s\n",fname);
        exit(EXIT_1);
    }
    printf("Please insert the pisition you want to print.\n");
    int local = 0;
    if(scanf("%d",&local)!=1)      //输入非正值  退出
    {
        printf("Please insert integer.\n");
        return;
    }
    else if (local<0)
    {
        printf("Please insert integer.\n");
        return;
    }
    
    char c;
    count = 0;
    while((ch = getc(fp)) != EOF && count < 1024*1024 && c != '\n')
    {
        count++;
        if(count>local)
        {
            printf("%c",ch);
            c = ch;
        }
        
    }
   
    fclose(fp);
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



#include <stdio.h>
#include <string.h>

#define STRLONG 100

extern char iswithin(char ch,char *str,int len) ;
extern char * s_gets(char *st,int n);

char* string_in(char *str1,int len1,char *str2,int len2)
{
    //确定str1中  是否包含str2 若不包含 则返回空指针 
    //包含 返回str1字符串中的 str2 字符串 首字符地址
    char *ret = str1;
    char flag = 1;  //str1 中 有str2的每个字符  否则为0
    printf("str1_len = %d, str2_len = %d\n",len1,len2);
    if(len1>=len2)
    {
        //确定str2中  每个字符能否在str1中被找到
        for(int i=0; i<len2; i++)   
        {
            if(iswithin(str2[i],str1,strlen(str1))==0)
            {
                flag = 0;
                break;
            }
        }

        if(flag)    //str2 的每个字符在 str1中都能被找到
        {
            for(int i=0; i<len1; i++)  
            {
                if(str2[0]==str1[i])
                {
                    ret = (str1+i);
                    for(int j=1;j<len2; j++)    //按顺序比较每个字节
                    {
                        if(str2[j]==str1[i+j])
                        {}
                        else
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag)
                    {
                        break;  //找到 终止寻找
                    }
                    else
                    {
                        flag = 1;
                    }
                }   //end... if(str2[0]==str1[i])  
            }
        }//end...  if(flag)    //str2 的每个字符在 str1中都能被找到

    }
    else
    {
        flag = 0;
    }
    if(flag==0)
    {
        ret = NULL;
    }
    return ret;
}
void test_11_8(void)
{
    char str1[STRLONG],str2[STRLONG];
    char *posi = NULL;
    printf("Please input string1:\n");
    s_gets(str1,STRLONG);
    printf("Please input string2:\n");
    s_gets(str2,STRLONG);

    posi = string_in(str1,strlen(str1),str2,strlen(str2));
    if(posi==NULL)
    {
        printf("str1 not include str2.\n");
    }
    else
    {
        printf("str1 include str2 and the position is %p \n",posi);
        for(int temp=0;temp<strlen(str2);temp++)
        {
            printf("%c",*(posi+temp));
        }
        printf("\n");
    }
    

}


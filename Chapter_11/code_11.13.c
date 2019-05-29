#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Chapter11-Q13
拆分字符串为单词
反序输出单词
*/
#define LENGTH 255

extern char * s_gets(char *st,int n);
void print_inverse_str_sort(char* str,int len);
void word_print(char *str);

void test_11_13(void)
{
    char *str = malloc(sizeof(char)*LENGTH);
    printf("Please input string.\n");
    s_gets(str,LENGTH);

    print_inverse_str_sort(str,strlen(str));

}

void print_inverse_str_sort(char* str,int len)
{
    char *p = str;
    char *arr[100];
    int num = 0;
    
    arr[0] = str;
    //按单词  逆序输出
    for(int k=0; k<len; k++)
    {
        if(*(str+k) == 32)
        {
            while(*(str+k)==32 && k<len)
                k++;
            num++;
            arr[num] = str+k;  //存储地址 
        }
    }
    printf("%d \n",num);

   for(int k=num; k>=0; k--)
   {
       word_print(arr[k]);
   }
    printf("\n");

}
void word_print(char *str)
{
    int i = 0;
    static int numm = 0;
    numm++;
    while(*(str+i) != 32 && *(str+i) != '\0' )
    {
        printf("%c",*(str+i));
        i++;
    }
    printf(" ");
        
}


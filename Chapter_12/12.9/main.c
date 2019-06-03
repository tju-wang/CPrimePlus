#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
C PrimerPlus
Chapter12.5
100个1-10的随机数  并以降序排列
Chapter12.6
统计随机数0-10  各个数字出现的次数  使用rand() 与 srand()函数
Chapter12.9
编写符合描述的函数

time(NULL)  返回值为系统当前对应的 s 数

srand(x) 设置rand函数种子为x


*/
char invertSort(int *data,int num);   //简单的冒泡排序
int statisticData(int *data,int dataNum,int findData);
void test_12_9(void);
void test_12_6(void);

void main(void)
{

    // test_12_6();
    test_12_9();



}


char invertSort(int *data,int num)   //简单的冒泡排序  降序
{   
    int i,j;

    int temp,min;
    if(num>0)
    {
        for( i=0; i<num ;i++)
        {
            min = *(data+i);
            for(j=i; j<num; j++)    
            {
                if(min<*(data+j))  //交换值的位置
                {
                    temp = *(data+j);
                    *(data+j) = min;
                    *(data+i) = temp;
                    min = *(data+i);
                }

            }
        }

    }
    return 1;
}

/*
统计数组中  该数字出现的次数
*/
int statisticData(int *data,int dataNum,int findData)
{
    int ret = 0;
    for(int i=0;i<dataNum;i++)
    {
        if(findData==*(data+i))
            ret++;
    }

    return ret;
}
void test_12_6(void)
{
    int arr[1000] = {0};
    int dataNum[10] = {0};  //统计0-9  各个数字出现的次数
    int i;
    printf("time = %d\n",time(NULL));
    srand(time(NULL));
    printf("time = %d\n",time(NULL));
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++)  {
        arr[i] =  (rand()%10);
    }

    for(i=0;i<10;i++)
    {
        dataNum[i] = statisticData(arr,(sizeof(arr)/sizeof(int)),i);
        printf("Num %d appear %d times. \n",i,dataNum[i]);
    }
}

/*自定义字符串读取函数  
注意 函数不适用于读取单个字符
原因是fgets函数 在字符串末尾自动添加"\n"  此时会被函数替换为"\0"
 */

char * s_gets(char *st,int n)
{
    char * ret_val;
    int i = 0;

    while (getchar() != '\n')
        continue;

    ret_val = fgets(st,n,stdin);
    // printf("1.");
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

/*输出单个单词  输入地址 遇到空格 停止输出  最长输出100个字母的单词 */
void word_print(char *str)
{
    int i = 0;
    static int numm = 0;
    numm++;
    while(*(str+i) != 32 && *(str+i) != '\0' && i<100 )
    {
        printf("%c",*(str+i));
        i++;
    }
    printf(" ");
        
}

void test_12_9(void)
{
    int WordsNum = 0;
    printf("How many words do you wish to enter? \n");
    scanf("%d",&WordsNum);
      
    if(WordsNum)
    {
        char **pArr= NULL;
        pArr = (char **)malloc(sizeof(char*)*WordsNum);       //注意为 指针数组申请内存的写法
        // char str[100];
        char *str = malloc(sizeof(char)*255);
        printf("Enter %d Wors now.\n",WordsNum);

        s_gets(str,255);

        //拆分字符串  找出每个单词的地址 存入 *pArr[] 中
        int len  = strlen(str);  

        int num = 0;
        *pArr = str;

        for(int k=0; k<len; k++)
        {
            if(*(str+k) == 32 && num < WordsNum)
            {
                while(*(str+k)==32 && k<len)
                    k++;
                num++;
                *(pArr+num) = str+k;  //存储地址 
            }
        }
        //按照字符数组中的存储内容  输出各单词
        printf("Here are your words:\n");

        for(int numm=0; numm<WordsNum; numm++)
        {
            word_print(*(pArr+numm));
            printf("\n");
        }
        free(pArr);
    }
    

}



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
C PrimerPlus
Chapter12.5
100个1-10的随机数  并以降序排列
Chapter12.6
统计随机数0-10  各个数字出现的次数  使用rand() 与 srand()函数

time(NULL)  返回值为系统当前对应的 s 数

srand(x) 设置rand函数种子为x


*/
char invertSort(int *data,int num);   //简单的冒泡排序
int statisticData(int *data,int dataNum,int findData);
void main(void)
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



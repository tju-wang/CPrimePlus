#include <stdio.h>
#include <stdlib.h>


/*
C PrimerPlus
Chapter12.5
100个1-10的随机数  并以降序排列

*/
char invertSort(int *data,int num);   //简单的冒泡排序
void main(void)
{
    int arr[100] = {0};

    for(int i=0;i<(sizeof(arr)/sizeof(int));i++)  {
        arr[i] =  (rand()%10);
    }
    
    invertSort(arr,(sizeof(arr)/sizeof(int)));

    for(int i=0;i<(sizeof(arr)/sizeof(int));i++)   
    {
        printf("%d  ",arr[i]);
        if(i%8==7)
            printf("\r\n");
        
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


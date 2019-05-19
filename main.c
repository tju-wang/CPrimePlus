#include <stdio.h>
#include <stdlib.h>


/*
C PrimerPlus
Chapter12.5
100个1-10的随机数  并以降序排列

*/
void main(void)
{
    int arr[100] = {0};

    for(int i=0;i<100;i++)  {
        arr[i] =  (rand()%10);
        printf("%d  ",arr[i]);
    }
   


}




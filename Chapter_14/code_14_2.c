#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Q2  输入当前日期  返回今年已经过去多少天

 */

extern int CalcDays(int monNum);
extern void RecognizeMonth(char pMon[4],int *num);
char ChackFormat(int year,int monNum,int day);

struct Month
{
    char name[15];
    char abbName[4];
    int Days;
    int Number;
};
// extern struct Month monthSets[12];
extern struct Month monthSets[12]; 

void test_14_2(int argv, char *argc[])
{
    int monNum = 0;
    int days = 0;
    char dateformat = 0;
    char str[20];
    int year,mon,day;

    // printf("Please input a month number:\n");
    // printf("Please input abbreviation of month.\n");

    do
    {
        // printf("Please input correct date format.\n");
        printf("Please input todey's date.\neg.\n2019.05.20\n");
        scanf("%d.%d.%d",&year,&mon,&day);
        dateformat = ChackFormat(year,mon,day);
    }while(dateformat==0);
    //计算时间  check 确保了输入的月份是 1-12
    days = CalcDays(mon-1) + day;
    printf("%d days have passed in %d year!",days,year);   
}

//检查输入的日期格式
char ChackFormat(int year,int monNum,int day)
{
    char ret = 1;
    // printf("%d   %d\n",monNum,day);
    if(monNum<0 || monNum>12)
    {
        return 0;
    }
    if (day<0 || day>31)
    {
        return 0;
    }
    
    return ret;
}








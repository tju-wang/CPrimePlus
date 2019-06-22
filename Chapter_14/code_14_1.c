#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// void monthStructInit(struct Month monthSets);
int CalcDays(int monNum);
void RecognizeMonth(char pMon[4],int *num);


struct Month
{
    char name[15];
    char abbName[4];
    int Days;
    int Number;
};
struct Month monthSets[12] = {
    {"January", "JAN", 31, 1},
    {"February", "FEB", 30, 2},
    {"March", "MAR", 31, 3},
    {"April", "APR", 30, 4},
    {"May", "MAY", 31, 5},
    {"June", "JUN", 30, 6},
    {"July", "JUL", 31, 7},
    {"August", "AUG", 31, 8},
    {"September", "SEP", 30, 9},
    {"October", "OCT", 31, 10},
    {"November", "NOV", 30, 11},
    {"December", "DEC", 31, 12}

};



void test_14_1(int argv, char *argc[])
{
    int monNum = 0;
    int days = 0;
    struct Month tempMonth;
    // printf("Please input a month number:\n");
    printf("Please input abbreviation of month.\n");
    scanf("%s",&(tempMonth.abbName));
    // printf("%s  \n",tempMonth.abbName);
    RecognizeMonth(&(tempMonth.abbName[0]),&monNum);
    days = CalcDays(monNum);

    printf("days = %d\n",days);


}

//返回当年到本月（包括本月）的总天数
int CalcDays(int monNum)
{
    int num = 0;
    int ret = 0;
    if(monNum>0 && monNum<13)
    {
        for(num=1; num<monNum+1; num++)
        {
            ret += monthSets[num-1].Days;
        }
    }
    else
    {
        return 0;
    }
    return ret;
}

void RecognizeMonth(char pMon[4],int *num)
{
    // for(int k=0;k<4;k++)    {
    //     printf("%c",pMon[k]);
    // }
    // printf("\n");
    int i = 0;
    for(i=1; i<13; i++)
    {
        if(strcmp(pMon,(monthSets[i-1].abbName))==0)
            break;
            
    }
    *num = i;
}


// void monthStructInit(struct Month monthSets)
// {
//     monthSets = {
//         .name = "January",
//         .abbName = "JAN",
//         .Days = 31,
//         .Number = 1,
//     };

// }



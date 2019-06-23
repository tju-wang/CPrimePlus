#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Q8 巨人航空公司座位预订系统

 */

#define SEATSNUMBER   12

void display(void);
void menuAnalysis(char ch);

struct member_t
{
    unsigned int seatNumber;
    char state;
    char firstName[20];
    char lastName[20];
};
struct member_t data[SEATSNUMBER] = {
    {1,0},
    {2,0},
    {3,0},
    {4,0},
    {5,0},
    {6,0},
    {7,0},
    {8,0},
    {9,0},
    {10,0},
    {11,0},
    {12,0},
};

void test_14_5(int argv, char *argc[])
{
    //初始化座位编号  座位状态

    while (1)
    {
        display();
    }
    
    
    
}

void display(void)
{
    char input;
    printf("To choose a function, enter its letter lable:\n");
    printf("a) Show number of empty seats.\n");
    printf("b) Show list of empty swats.\n");
    printf("c) Show alphabetical list of seats.\n");
    printf("d) Assign a customer to a seat assignment.\n");
    printf("e) Delete a seat assignment.\n");
    printf("f) Quit.\n");
    scanf("%c",&input);
    menuAnalysis(input);

}

void showEmptNum(struct member_t *p)
{
    printf("The number of empty seats.\n");
    for(int k=0; k<SEATSNUMBER; k++)
    {
        if(p->state == 0)
        {
            printf("Sort %d is empty.\n",p->seatNumber);
        }
    }
}

void menuAnalysis(char ch)
{
    switch(ch)
    {
        case "\a":
        {
            showEmptNum(&data);
        }break;
        case "b":
        {

        }break;
        case "c":
        {

        }break;
        case "d":
        {

        }break;
        case "e":
        {

        }break;
        case "f":
        {
            EXIT(1);
        }break;
        default:
        {}break;
    }
}



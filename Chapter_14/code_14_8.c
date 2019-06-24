#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Q8 巨人航空公司座位预订系统

 */

#define SEATSNUMBER   12

void display(void);
void menuAnalysis(char ch);
void clearInputChar(void);


struct member_t
{
    int seatNumber;
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

void test_14_8(int argv, char *argc[])
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
    //下列两行 吃掉换行符  吃掉第一个字符以为的其他字符
    
    menuAnalysis(input);

}

void showEmptNum(struct member_t (*p))      //使用指针方式  非数组指针  指针++  相当于移动到下一个结构体
{
    printf("The number of empty seats.\n");
    static int k=0;
    for(k=0; k<SEATSNUMBER; k++)
    {
        if(p->state == 0)
        {
            printf("%d Sort %d is empty.\n",k,(p++)->seatNumber);
        }
    }
}
void showEmptNumList(struct member_t (*p))
{
    printf("The number list of empty seats.\n");
    int count = 0;
    int emptList[SEATSNUMBER];
    for(int k=0; k<SEATSNUMBER; k++)
    {
        if(p->state==0)
        {
            emptList[count] = p->seatNumber;
            count++;
        }
    }
    for(int k=0; k<count; k++)
    {
        printf("%d  ",emptList[count]);
    }
    printf("\n");
}

//按照姓名  的首字母排序输出名字及座位信息
void showInfoAlphaSort(struct member_t (*p))
{

}
void assignCust(struct member_t (*p))
{
    char firstName[20];
    char lastName[20];
    int seatNumber;
    printf("Input customer first name and last name.")
    scanf("%s.%s",&firstName,&lastName);
    clearInputChar();
    printf("Input the number of seat.")
    scanf("%d",seatNumber);
    clearInputChar();
    for(int k=0; k<SEATSNUMBER; k++)
    {
        if(seatNumber==p->seatNumber)
        {
            if(p->state==0)
            {
                p->state = 1;   //标记状态
                strcpy(&p->firstName,&firstName);
                strcpy(&p->lastName,&lastName);
            }
            else
            {
                printf("This seat have be booked. Please Input again.")
            } 
        }
    }


}
void deleteSeatAssign(struct member_t (*p))
{   
    for(int k=0; k<SEATSNUMBER; k++)
    {
        
    }

}

void menuAnalysis(char ch)
{
    switch(ch)
    {
        case 'a':
        {
            showEmptNum(&data[0]);
        }break;
        case 'b':
        {
            showEmptNumList(&data[0]);
        }break;
        case 'c':
        {

        }break;
        case 'd':
        {

        }break;
        case 'e':
        {

        }break;
        case 'f':
        {
            exit(1);
        }break;
        default:
        {
            printf("Input error.Again!");
        }break;
    }
}

void clearInputChar(void)
{
    while(getchar()!='\n')
        continue;
}



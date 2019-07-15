#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Q9  巨人航空公司座位预订系统  功能拓展

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
struct member_t data[4][SEATSNUMBER] = {
 {  {1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0},{11,0},{12,0},  },
 {  {1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0},{11,0},{12,0},  },
 {  {1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0},{11,0},{12,0},  },
 {  {1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0},{11,0},{12,0},  },
  
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
    clearInputChar();
    menuAnalysis(input);

}

void showEmptNum(struct member_t (*p))      //使用指针方式  非数组指针  指针++  相当于移动到下一个结构体
{
    printf("The number of empty seats.\n");
    static int k=0;
    for(k=0; k<SEATSNUMBER; k++, p++)
    {
        if(p->state == 0)
        {
            printf("seat %d is empty.\n",(p)->seatNumber);
        }
    }
}
void showEmptNumList(struct member_t (*p))
{
    printf("The number list of empty seats.\n");
    int count = 0;
    int emptList[SEATSNUMBER];
    for(int k=0; k<SEATSNUMBER; k++, p++)
    {
        if(p->state==0)
        {
            emptList[count] = p->seatNumber;
            // printf("%d  %d\n",p->state,p->seatNumber);
            count++;
        }
    }
    for(int k=0; k<count; k++)
    {
        printf("%d  ",emptList[k]);
    }
    printf("\n");
}

//按照姓名  的首字母排序输出名字及座位信息
void showInfoAlphaSort(struct member_t (*p))
{
    printf("The alphabetical list of seats.\n");
    struct member_t temp_data[SEATSNUMBER];
    struct member_t tem_stru;
    int count = 0;
    for(int k=0; k<SEATSNUMBER;k++, p++)
    {
        if(p->state==1)
        {
            temp_data[count++] = *p;       //结构体间初始化
        }
    }
    //有乘客的结构体 被复制
    tem_stru = temp_data[0];
    printf("%d  \n",count);
    for(int k=0; k<count; k++)
    {
        for(int t=k; t<count; t++)
        {
            if(temp_data[k].firstName[0] > temp_data[t].firstName[0])   //换序
            {
                tem_stru = temp_data[k];
                temp_data[k] = temp_data[t];
                temp_data[t] = tem_stru;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s %s seatNumber is %d \n",temp_data[i].firstName,temp_data[i].lastName,temp_data[i].seatNumber);
    }


}
void assignCust(struct member_t (*p))
{
    char firstName[20];
    char lastName[20];
    int seatNumber;
    char st = 0;
    printf("Input customer first name and last name.\n");
    scanf("%s %s %d",&firstName,&lastName,&seatNumber);
    printf("%s  \n%s  \n",firstName,lastName);  //输入格式：  wang xing 8
    printf("seat Number = %d\n",seatNumber);
    clearInputChar();
    for(int k=0; k<SEATSNUMBER; k++, p++)
    {
        if(seatNumber==p->seatNumber)
        {
            st = 1;
            if(p->state==0)
            {
                p->state = 1;   //标记状态
                strcpy(&(*p->firstName),firstName);
                strcpy(&(*p->lastName),lastName);
            }
            else
            {
                printf("This seat have be booked. Please Input again.\n");
            } 
        }
    }
    if(st==0)
    {
        printf("The seat number is not exist.\n");
    }
}
void deleteSeatAssign(struct member_t (*p))
{   
    int seatNumber;
    char st = 0;
    printf("Please insert the seat number you wang to delete.\n");
    // clearInputChar();
    // getchar();
    scanf("%d",&seatNumber);
    // printf("seatnumber = %d",seatNumber);
    for(int k=0; k<SEATSNUMBER; k++,p++)
    {
        if(p->seatNumber == seatNumber)
        {
            st = 1;
            if(p->state==1) 
            {
                p->state = 0;
                for(int t=0; t<20; t++)
                {
                    p->firstName[t] = '\0';
                    p->lastName[t] = '\0';
                }
                printf("Delete success.\n");
            }
            else
            {
                printf("The seat is empyt. Delete fail.\n");
            }
        } 
    }
    if(st==0)
    {
        printf("The seat number is not exist.\n");
    }
}

void menuAnalysis(char ch,char sort)
{
    //将  传入函数的参数  变为二维的
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
            showInfoAlphaSort(&data[0]);
        }break;
        case 'd':
        {
            assignCust(&data[0]);
        }break;
        case 'e':
        {
            deleteSeatAssign(&data[0]);
        }break;
        case 'f':
        {
            exit(1);
        }break;
        default:
        {
            printf("Input error.Again!\n");
        }break;
    }
}

void clearInputChar(void)
{
    while(getchar()!='\n')
        continue;
}





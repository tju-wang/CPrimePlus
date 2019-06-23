#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//处理图片的尺寸 行 列
#define RAW 20
#define COLUMN   30

void pixelConvert(int data[][31],int raw, int column, int ret_data[][31]);
int dataConvert(int *data, int *diff, int num);
int dataType(int raw, int column);


/*
从文件读取图片信息  转化为图片
放弃做12题  没有意义  数字与字符之间的转换没有规律  图片看着效果也不好

直接做14题
后续Q14进行图片处理
 */

void test_13_14(int argc,char *argv[])
{
    FILE *fp;
    int data[20][31] = {0};
    int count = 0;
    int raw_counter = 0;
    int ch;
    if((fp = fopen(argv[1],"r")) == NULL)
    {
        printf("Can not open file.\n");
        return ;
    }

    while((ch = getc(fp)) != EOF && count <31)
    {
        if(ch != ' ')   {
            data[raw_counter][count] = ch;
            count++;
            if(ch=='\n')
            {
                data[raw_counter][count-1] = '\0';
                raw_counter++;
                count = 0;
            }


        }
    }
    int end_data[20][31];

    for(int raw=0; raw<RAW; raw++)
    {
        for(int column=0; column<31; column++)
        {
            pixelConvert(&data[0],raw,column,&end_data[0]);
        }
    }

    for(int raw=0; raw<RAW; raw++)
    {
        for(int column=0; column<31; column++)
        {
            printf("%c ",data[raw][column]);
        }
        printf("\r\n");
    }

    printf("\n");
    for(int raw=0; raw<RAW; raw++)
    {
        for(int column=0; column<31; column++)
        {
            printf("%c ",end_data[raw][column]);
        }
        printf("\r\n");
    }
    
    
}

void pixelConvert(int data[][31],int raw, int column, int ret_data[][31])
{
    int data_type = 0;
    int diff[5] = {0};
    data_type = dataType(raw,column);
    //switch 对8种边缘进行选择处理
    switch(data_type)
    {
        case 0:
        {
            diff[1] = data[raw][column] - data[raw][column-1];
            diff[2] = data[raw][column] - data[raw][column+1];
            diff[3] = data[raw][column] - data[raw-1][column];
            diff[4] = data[raw][column] - data[raw+1][column];
            ret_data[raw][column] = dataConvert(&data[raw][column],&diff[0],4);
        }break;
        case 1:
        {
            diff[1] = data[raw][column] - data[raw][column+1];
            diff[2] = data[raw][column] - data[raw+1][column];
            diff[0] = 0;
            ret_data[raw][column] = dataConvert(&data[raw][column],diff,2);
        }break;
        case 2:
        {
            diff[1] = data[raw][column] - data[raw][column-1];
            diff[2] = data[raw][column] - data[raw+1][column];
            diff[0] = 0;
            ret_data[raw][column] = dataConvert(&data[raw][column],diff,2);
        }break;
        case 3:
        {
            diff[1] = data[raw][column] - data[raw][column+1];
            diff[2] = data[raw][column] - data[raw-1][column];
            diff[0] = 0;
            ret_data[raw][column] = dataConvert(&data[raw][column],diff,2);
        }break;
        case 4:
        {
            diff[1] = data[raw][column] - data[raw][column-1];
            diff[2] = data[raw][column] - data[raw-1][column];
            diff[0] = 0;
            ret_data[raw][column] = dataConvert(&data[raw][column],diff,2);
        }break;
        case 5:
        {
            diff[1] = data[raw][column] - data[raw][column+1];
            diff[2] = data[raw][column] - data[raw][column-1];
            diff[3] = data[raw][column] - data[raw+1][column];
            diff[0] = 0;
            ret_data[raw][column] = dataConvert(&data[raw][column],diff,3);
        }break;
        case 6:
        {
            diff[1] = data[raw][column] - data[raw][column+1];
            diff[2] = data[raw][column] - data[raw][column-1];
            diff[3] = data[raw][column] - data[raw-1][column];
            diff[0] = 0;
            ret_data[raw][column] = dataConvert(&data[raw][column],diff,3);
        }break;
        case 7:
        {
            diff[1] = data[raw][column] - data[raw-1][column];
            diff[2] = data[raw][column] - data[raw+1][column];
            diff[3] = data[raw][column] - data[raw][column+1];
            diff[0] = 0;
            ret_data[raw][column] = dataConvert(&data[raw][column],diff,3);
        }break;
        case 8:
        {
            diff[1] = data[raw][column] - data[raw-1][column];
            diff[2] = data[raw][column] - data[raw+1][column];
            diff[3] = data[raw][column] - data[raw][column-1];
            diff[0] = 0;
            ret_data[raw][column] = dataConvert(&data[raw][column],diff,3);
        }break;

    }
    //确定情况后的数据处理
}
int dataConvert(int *data, int *diff, int num)
{
    int ret_data;
    int flag;
    flag = 1;
    *diff = 0;
    for(int i=1; i<num+1 && flag == 1; i++)
    {
        if(((diff[i]>=0 && diff[i]<=1) || (diff[i]<0 && diff[i] >= -1)) )
            flag = 0;
        diff[0] += diff[i];
    }
    if(flag)
    {
        if(diff[0]<0)
            ret_data = -(int)(((float)diff[0])/num - 0.5) + *data ;
        else
            ret_data = -(int)(((float)diff[0])/num + 0.5) + *data ;
    }
    else
    {
        ret_data = *data;
    }


    return ret_data;

}


int dataType(int raw, int column)
{
    int data_type = 0;
    //判断是否是边缘  那种边缘
    if(raw==0)
    {
        if(column==0)
        {
            data_type = 1;  //左上角的数据
        }
        else if(column==COLUMN-1)   //右上角的数据
        {
            data_type = 2;
        }
        else
        {
            data_type = 5;  //上边沿
        }
    }
    else if (raw==RAW-1)
    {
        if(column==0)
        {
            data_type = 3;  //左下角角的数据
        }
        else if(column==COLUMN-1)   //右下角的数据
        {
            data_type = 4;
        }
        else
        {
            data_type = 6;  //下边沿
        }
    }
    else if(data_type==0 && column==0)
    {
        data_type = 7;  //左边沿
    }
    else if (data_type==0 && column==COLUMN-1)
    {
        data_type = 8;  //右边沿
    }

    return data_type;
}

//按书上的例子 显示图片内容
// void display(int *data)
// {

// }



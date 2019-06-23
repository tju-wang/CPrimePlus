#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define EXIT_1  1
#define EXIT_2  2

void test_13_2(int argc, char *argv[])
{
    int count = 0;
    if(argc != 3)
    {
        printf("Please input two files name.\n");
    }
    // else
    // {
    //     puts(argv[1]);
    //     printf("2. \n");
    //     puts(argv[2]);
    // }
    
    //打开文件  获取原始文件名  拷贝文件名
    FILE *fp_read,*fp_write;
    char ch;
    if((fp_read = fopen(argv[1],"rb")) == NULL)
    {
        printf("Can't open %s\n",argv[1]);
        exit(EXIT_1);
    }
    if((fp_write = fopen(argv[2],"wb")) == NULL)
    {
        printf("Can't open %s\n",argv[2]);
        exit(EXIT_2);
    }
    while((ch = getc(fp_read)) != EOF && count < 1024*1024 )
    {
        putc(ch,stdout);
        putc(ch,fp_write);
        count++;
    }

    fclose(fp_read);
    fclose(fp_write);
    
}


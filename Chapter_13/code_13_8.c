#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define EXIT_1  1
#define EXIT_2  2
int findChar(char *filename,char fch);

void test_13_8(int argc, char *argv[])
{
    int count = 0;
    if(argc == 1 )
    {
        printf("Please input a char.\n");
    }
    else if (argc == 2)
    {
        printf("The inout char is \'%c\' \n",*argv[1]);
    }
    else
    {
        for(int i=2; i<argc; i++)
        {
            printf("The char \'%c\' are found in the file %s *%d times\n",*argv[1],argv[i],findChar(argv[i],*argv[1]));
        }
    }
    
}

int findChar(char *filename,char fch)
{
    int ret = 0;
    FILE *fp;
    char ch;
    int count = 0;
    if((fp = fopen(filename,"rb")) == NULL)
    {
        printf("Can't open %s\n",filename);
        return ret;
    }
    while((ch = getc(fp)) != EOF && count < 1024*1024 )
    {
        count++;
        if(ch==fch)
            ret++;
    }
    fclose(fp);
    
    return ret;

}




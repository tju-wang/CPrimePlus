#include <stdio.h>
#include <string.h>

/*
C PrimerPlus
Chapter11--Q1


*/

char * s_gets(char *st,int n);


int main (int argc,char *argv[])
{
    char mchar[20];

    s_gets(mchar,20);
    
    puts(mchar);

    return 0;
}

char * s_gets(char *st,int n)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        while (st[i] != '\n' && st[i] !='\0')
            i++;
        if(st[i]=='\n')     //替换换行符  为‘\0’
            st[i] = '\0';
        else
        {
            // while (getchar() != '\n')
            //     continue;
        }
        
    }
    return ret_val;
}



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Q5  编写满足下列要求的程序
 */

#define CSIZE 4

struct name_t
{
    char firstName[10];
    char lastName[10];
};


struct student_t
{
    struct name_t name;
    float grade[3];
    float ave;
};

struct student_t stud[CSIZE] = {
    { "abc","def" },
    { "abc","def" },
    { "abc","def" },
    { "abc","def" },
};


void test_14_5(int argv, char *argc[])
{

    printf("Please input students name.(Wang.)")
    printf("%s  %s  \n",stud[0].name.firstName,stud[0].name.lastName);



}




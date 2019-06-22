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

void CalvAve(struct student_t *stu);
void StruPrint(const struct student_t *stu);
void StruFileprint(FILE *fp,const struct student_t *stu);

void test_14_5(int argv, char *argc[])
{

    for(int k=0; k<CSIZE; k++)
    {
        printf("Please input the number %d students name.(FirstName LastName)\n",k+1);
        scanf("%s %s",&stud[k].name.firstName,&stud[k].name.lastName);
        printf("Please enter her/his grades for three courses.\n");
        scanf("%f  %f  %f",&stud[k].grade[0],&stud[k].grade[1],&stud[k].grade[2]);
    }
    for(int k=0; k<CSIZE; k++)
    {
        printf("%s  %s\n",stud[k].name.firstName,stud[k].name.lastName);
        printf("%f  %f  %f\n",stud[k].grade[0],stud[k].grade[1],stud[k].grade[2]);
        CalvAve(&stud[k]);
        printf("the ave = %f \n",stud[k].ave);
    }
    for(int k=0; k<CSIZE; k++)
    {
        StruPrint(&stud[k]);
    }

    FILE *fp;
    if((fp = fopen(argc[1],"wb")) == NULL)
    {
        printf("Can't open %s\n",argc[1]);
        exit(1);
    }
    for(int k=0; k<CSIZE; k++)
    {
        StruFileprint(fp,&stud[k]);
    }
    
}

void CalvAve(struct student_t *stu)
{
    (*stu).ave = 0.0;
    for(int k=0; k<3; k++)
    {
        (*stu).ave += (*stu).grade[k];
    }
    (*stu).ave = (*stu).ave / 3;
}
//打印结构体内容
void StruPrint(const struct student_t *stu)
{
    printf("name.firstName = %s  name.lastName = %s\n",stu->name.firstName,stu->name.lastName);
    printf("grade[3] = %f  %f  %f  ave = %f  \n",stu->grade[0],stu->grade[1],stu->grade[2],stu->ave);  
}

void StruFileprint(FILE *fp,const struct student_t *stu)
{
    fprintf(fp,"name.firstName = %s  name.lastName = %s\n",stu->name.firstName,stu->name.lastName);
    fprintf(fp,"grade[3] = %f  %f  %f  ave = %f  \n",stu->grade[0],stu->grade[1],stu->grade[2],stu->ave);  
}




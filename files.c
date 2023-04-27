#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void write(FILE *fp);
void read(FILE *fp);
void Vaccinated_students(FILE *fp);
void main()
{
    FILE *fp;
    write(fp);
    read(fp);
    Vaccinated_students(fp);
}

void write(FILE *fp)
{

    char student_name[10];
    int student_id,vaccinated,n,i;
    fp=fopen("vaccine.txt","w");
    printf("Enter the number of students\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the student ID\n");
        scanf("%d",&student_id);
        printf("Enter the student name\n");
        scanf("%s",student_name);
        printf("is student vaccinated if yes press 1 else 0\n");
        scanf("%d",&vaccinated);
        if(i!=n)
            fprintf(fp,"%d\t%s\t%d\n",student_id,student_name,vaccinated);
        else
            fprintf(fp,"%d\t%s\t%d",student_id,student_name,vaccinated);
    }
fclose(fp);
}
void read(FILE *fp)
{


    int student_id,vaccinated;// vaccinated=1 else 0
    char student_name[10];
    fp=fopen("vaccine.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d%s%d",&student_id,student_name,&vaccinated);
        printf("student ID= %d\n",student_id);
        printf("student name= %s\n",student_name);
        printf("student vaccinated_status =%d\n",vaccinated);
    }
fclose(fp);
}
void Vaccinated_students(FILE *fp)
{

    char student_name[10];
    int student_id,vaccinated;
    printf("\n\nDisplaying vaccinated students\n");
    fp=fopen("vaccine.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d%s%d",&student_id,student_name,&vaccinated);
        if(vaccinated==1)
        {
            printf("student ID= %d\n",student_id);
            printf("student name= %s\n",student_name);
            printf("student RAM =%d\n",vaccinated);
        }
    }
fclose(fp);
}

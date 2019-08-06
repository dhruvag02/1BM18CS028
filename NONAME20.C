#include<stdio.h>
#include<conio.h>
#define N 3
#define SUB 2
int main()
{
struct student
{
char name[20];
char usn[20];
int marks[SUB];
};
struct student stud[N];
int i,j;
clrscr();
printf("****Enter student details***\n");
for(i=0;i<N;i++)
{
printf("Details of student%d\n",i+1);
printf("Enter name=");
scanf("%s",stud[i].name);
printf("Enter USN=");
scanf("%s",stud[i].usn);
for(j=0;j<SUB;j++)
{
printf("marks[%d]=",j);
scanf("%d",&stud[i].marks[j]);
}
}
printf("**** Student details are displayed***\n");
for(i=0;i<N;i++)
{
printf("Student%d\n",i);
printf("Name=%s\n",stud[i].name);
printf("USN=%s\n",stud[i].usn);
printf("Marks");
for(j=0;j<SUB;j++)
{
printf("Marks[%d]=%d\t",j,stud[i].marks[j]);
}
}
getch();
return 0;
}
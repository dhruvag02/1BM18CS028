#include<stdio.h>
#include<conio.h>
int main()
{
struct student
{
char name[100];
int rollno;
int ld,ds,dm;
};
struct student stud1;
char grade;
float sgpa;
int total;
clrscr();
printf("\n******enter marks of students of 3rd sem******\n");
printf("\n enter name");
scanf("%s",stud1.name);
printf("\n enter roll number");
scanf("%d",&stud1.rollno);
printf("\n enter marks in logic design");
scanf("%d",&stud1.ld);
printf("\n enter marks in data structure");
scanf("%d",&stud1.ds);
printf("\n enter marks in discrete mathematics");
scanf("%d",&stud1.ds);
printf("\n *****marks of student****\n");
printf("\n marks in LD=%d",stud1.ld);
printf("\n marks in DS=%d",stud1.ds);
printf("\n marks in DM=%d",stud1.dm);
if(stud1.ld>=90)
printf("s grade");
if(stud1.ld>=75 && stud1.ld<90)
printf("A grade");
if(stud1.ld>=60 && stud1.ld<75)
printf("B grade");
if(stud1.ld>=45 && stud1.ld<60)
printf("C grade");
if(stud1.ld>=33 && stud1.ld<45)
printf("D grade");
else
printf("F grade");
getch();
return 0;
}



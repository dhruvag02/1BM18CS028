#include<stdio.h>
struct student
{
char name[50];
int age;
int marks;
char id[20];
};
int main()
{
struct student stud;
printf("Enter name,age,marks and id of student\n");
scanf("%s %d %d %s",stud.name,&stud.age,&stud.marks,stud.id);
printf("***Details of student***\n");
printf("name=%s,age=%d,marks=%d,id=%s\n",stud.name,stud.age,stud.marks,stud.id);
if(stud.marks>=0 && stud.marks<=1000 && stud.age>20)
{printf("Valid entry\n");
if(stud.marks>=65)
printf("Student is eligible\n");
else
printf("Student is not eligible\n");
}
else{ 
printf("Not a valid entry\n");
}
}
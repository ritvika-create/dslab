
#include<stdio.h>
struct student
{
    int id;
    int age;
    int marks;
};
void main()
{
    int n,i;
    struct student s[100];
    printf(" enter  no. of students\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the ID,Age and Marks of student %d :\n",i+1);
        scanf("%d %d %d",&s[i].id,&s[i].age,&s[i].marks);
        if(s[i].age<20 ||s[i].marks>100||s[i].marks<0)
        {
        printf("Invalid data");
        }
        else if(s[i].marks>=65)
        {
            printf("Student eligible for admission\n");
        }
        else
        printf("Student not eligible for admission\n");

    }
    return 0;
}

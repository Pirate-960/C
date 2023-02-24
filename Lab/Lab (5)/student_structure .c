#include<stdio.h>
struct stud
{
     int stud_id;
     char stud_name[20];
     int term;
};



void student(struct stud s)
{
     printf("Student details:\n");
     printf("--------------------------\n");
     printf("Student ID : %d",s.stud_id);
     printf("\nName        : %s",s.stud_name);
     printf("\nTerm         : %d",s.term);
}

int main()
{
	struct stud s;
	
     printf("Enter Student Details\n");
     printf("--------------------------\n");
     printf("Student ID : ");
     scanf("%d",&s.stud_id);
     printf("Name        : ");
     scanf("%s",s.stud_name);
     printf("Term        : ");
     scanf("%d",&s.term);
     printf("--------------------------\n");
     
     student(s);
     return 0;
}

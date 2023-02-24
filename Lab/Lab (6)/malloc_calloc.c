#include <stdio.h>
#include <stdlib.h>

struct Student{
    int stdid;
    double *homeworks;
    double midterm;
    double final;
    double overall;
};

typedef struct Student student;

void printGrades(student *stdptr){
    if(stdptr != NULL)
         printf("student id: %d overall grade %lf\n", stdptr->stdid , stdptr->overall);
}
 
void deleteStudent(student *stdarray[], int totalstudents, int id){
    int i;
    for(i = 0; i < totalstudents; i++){
        if(stdarray[i] != NULL && stdarray[i]->stdid == id){
            printf("found %d\n",i);
            free(stdarray[i]->homeworks);
            free(stdarray[i]);
            stdarray[i] = NULL;
            break;
        }
    }
}



int main( int argc, char *argv[]) {
    
    int noOfStudents;
    printf("Enter number of sudents\n");
    scanf("%d",&noOfStudents);
    student *students[noOfStudents];

    int readStd = 0;
    int answer = 1;
    int no_of_hws, i;

    double *homework;

    for(i =0; i < noOfStudents; i++)
        students[i] = NULL;

    while(answer == 1 && readStd < noOfStudents){
        
            students[readStd] = (student*)malloc(sizeof(student));
            printf("student id:\n");
            scanf("%d",&students[readStd]->stdid);
            printf("submitted number of homework :\n");
            scanf("%d",&no_of_hws);
             if(no_of_hws > 0){
                students[readStd]->homeworks = (double *)malloc(sizeof(double)*no_of_hws);
                homework =  students[readStd]->homeworks;
            }
            else
                students[readStd]->homeworks = NULL;
                
            students[readStd]->overall = 0.0;
            for(i=0; i < no_of_hws; i++){
                printf("hw_%d grade :\n",i+1);
                scanf("%lf", homework);
                students[readStd]->overall += *homework;
                homework++;
            }
            if(no_of_hws > 0){
                students[readStd]->overall = (students[readStd]->overall / no_of_hws) * 0.2;
                homework = NULL;
            }
            
            printf("midterm grade :\n");
            scanf("%lf",&students[readStd]->midterm);
            students[readStd]->overall += students[readStd]->midterm * 0.3;
            
            printf("final grade :\n");
            scanf("%lf",&students[readStd]->final);
            students[readStd]->overall += students[readStd]->final * 0.5;
            
            printf("overall %lf\n", students[readStd]->overall);
            readStd++;

        printf("Do you want to enter student :\n");
        scanf("%d",&answer);

    }  //malloc version



    /*while(answer == 1 && readStd < noOfStudents){
        
            students[readStd] = (student*)calloc(1,sizeof(student));
            printf("student id:\n");
            scanf("%d",&students[readStd]->stdid);
            printf("submitted homework number :\n");
            scanf("%d",&no_of_hws);
             if(no_of_hws > 0){
                students[readStd]->homeworks = (double *)calloc(no_of_hws,sizeof(double));
                 homework =  students[readStd]->homeworks;
            }
            else
                students[readStd]->homeworks = NULL;
            
            for(i=0; i < no_of_hws; i++){
                printf("hw_%d grade :\n",i+1);
                 scanf("%lf",homework);
                students[readStd]->overall += *homework;
                homework++;
            }
            if(no_of_hws > 0){
                students[readStd]->overall = (students[readStd]->overall / no_of_hws) * 0.2;
                 homeworks = NULL;
            }

            printf("midterm grade :\n");
            scanf("%lf",&students[readStd]->midterm);
            students[readStd]->overall += students[readStd]->midterm * 0.3;
            printf("final grade :\n");
            scanf("%lf",&students[readStd]->final);
            students[readStd]->overall += students[readStd]->final * 0.5;
            printf("overall %lf\n", students[readStd]->overall);
            readStd++;

        printf("Do you want to enter student :\n");
        scanf("%d",&answer);

    }*/  //calloc version

   deleteStudent(students, noOfStudents, 123);

    for(i = 0; i < readStd; i++)
        printGrades(students[i]);




    
    return 0;
}


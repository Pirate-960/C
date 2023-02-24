#include <stdio.h>
#include <stdlib.h>
 
 
int main( int argc, char *argv[]) {

    if(argc != 7){
        printf("command line arguments: name surname studentid midterm1 midterm2 final\n");
        exit(1);
    }

   int studentid = atoi(argv[3]);
   double midterm1 = atof(argv[4]);
   double midterm2 = atof(argv[5]);
   double final = atof(argv[6]);

    double overall = midterm1 * 0.2 + midterm2 * 0.3 + final * 0.5;

    printf("Student : %s %s Student ID : %d overall grade : %lf\n",argv[1],argv[2], studentid,overall);
   
   return 0;
}


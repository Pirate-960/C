#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct Painting {

    int canvasheight;
    int canvaswidth;
    int creationyear;
    char period[50];
};

struct Song {

    int duration;
    char genre[50];
};

typedef struct Painting paint;
typedef struct Song s;
struct Art{

    char title[60];
    char owner[70];
    double price;
    union {
        paint mypaint;
        s mysong;
    };
};

typedef struct Art art;

void printFavourite(art fav,int choice){
    printf("\ntitle : %sowner : %sprice : %lf\n",fav.title,fav.owner,fav.price);

   if(choice == 1){
        printf("canvas width : %d\tcanvas height : %d\n",fav.mypaint.canvaswidth,fav.mypaint.canvasheight);
        printf("creation year : %d\tperiod : %s\n",fav.mypaint.creationyear,fav.mypaint.period);
    }
   else if(choice == 2){
         printf("duration : %d\tgenre : %s\n",fav.mysong.duration,fav.mysong.genre);
    }
}
 
int main( int argc, char *argv[]) {
    art myart;
   
   int choice;
    printf("title : ");
    fgets(myart.title,59,stdin);
    printf("owner : ");
    fgets(myart.owner,69,stdin);
    printf("price : ");
    scanf("%lf",&myart.price);
    printf("Please enter the type of your favourite artwork -->  1 : Painting 2 : Song");
    scanf("%d",&choice);
   if(choice == 1){
        printf("canvas width : ");
        scanf("%d",&myart.mypaint.canvaswidth);
        printf("canvas height : ");
        scanf("%d",&myart.mypaint.canvasheight);
        printf("creation year : ");
        scanf("%d",&myart.mypaint.creationyear);
        printf("period : ");
        scanf("%s",myart.mypaint.period);
    }
   else if(choice == 2){
         printf("duration : ");
         scanf("%d",&myart.mysong.duration);
         printf("genre : ");
         scanf("%s",myart.mysong.genre);
    }
   else{
        printf("invalid type\n");
        exit(1);    
    }
    printFavourite(myart,choice);
   return 0;
}


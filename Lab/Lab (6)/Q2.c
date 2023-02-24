#include <stdio.h>
#include <stdlib.h>

typedef struct Person{
	int age;
	int salary;
}Person;

typedef struct Family{
	struct Person *members;
	int personCount;
}Family;

int findage(Family families[3]){
	int totalSalary[3]={0};
	int minSalary=999999;

	int familyIndex;
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<families[i].personCount;j++){
			totalSalary[i]+=families[i].members[j].salary;
		}
		if(totalSalary[i]<minSalary){
			familyIndex=i;
			minSalary=totalSalary[i];
		}
	}
	int richest=0;
	int richestAge;
	for(j=0;j<families[familyIndex].personCount;j++){
		if(families[familyIndex].members[j].salary>richest){
			richest=families[familyIndex].members[j].salary;
			richestAge=families[familyIndex].members[j].age;
		}
	}
	return richestAge;
}

int main(void) {
	Family families[3];
	int i,j;
	
	for(i=0;i<3;i++){
		printf("Please enter the person count in family %d: ", (i+1));
		scanf("%d",&families[i].personCount);
		families[i].members = calloc(families[i].personCount, sizeof(Person));
		if(families[i].members != NULL){
			for(j=0;j<families[i].personCount;j++){
				printf("Please enter the age and salary fields for person %d in family %d: ", (j+1), (i+1));
				scanf("%d",&families[i].members[j].age);
				scanf("%d",&families[i].members[j].salary);
			}
		}
	}

	printf("Age of the richest in the poorest family: %d", findage(families));
	return 0;
}

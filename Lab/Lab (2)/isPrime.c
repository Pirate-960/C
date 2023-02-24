#include <stdio.h>

int gcd(int, int); // function prototype

int main()
{
	int a, b;
	
	printf("Enter two integers: ");
	scanf("%d%d", &a, &b);
	
	printf("\n gcd value:%d", gcd(a,b));
	
	
	return 0;

} // end main

int gcd(int x, int y){
	
	int i, gcdvar = 1, lowest = x;
	
	if(x>y) 
		lowest = y;
	
	for(i=2; i<=lowest ; i++){
		if(x % i ==0 && y%i == 0 )
			gcdvar = i;	
	}

	return gcdvar;	
	
}





		
	

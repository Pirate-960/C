#include <stdio.h>

struct point {
	int x;
	int y;
};

struct square {
	struct point p;
	int length;
};

int area(struct square mySquare) {
	return mySquare.length * mySquare.length;
}

int perimeter(struct square mySquare) {
	return mySquare.length * 4;
}

int main(void) {

	//struct point p;
	struct square mySquare;

	scanf("%d %d %d", &mySquare.p.x, &mySquare.p.y, &mySquare.length);
	//mySquare.p = p;

	printf("%d %d %d\n", mySquare.p.x, mySquare.p.y, mySquare.length);

	printf("Area: %d Perimeter: %d\n", area(mySquare), perimeter(mySquare));

	return 0;
}

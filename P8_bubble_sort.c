#include<stdio.h>
#include<math.h>


int main(){
	int r=0;
	float pi=3.14;
	float area;
	float c;
	printf("Hello!\n");
	printf("Enter Radius of the Circle:");
	scanf("%d",&r);
	
	area = pi*r*r;
	c= 2*pi*(r);
	
    printf("Radius of a Circle: %d\n",r);
	printf("Area of the circle is: %f\n",area);
	printf("Circumference of the circle is: %f\n",c);		
}
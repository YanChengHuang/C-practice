#include <stdio.h>
#include <math.h>
int main()
{
	float f=5,g=10;
    int a=1,b=2;
	enum{i=10,j=20,k=50};
	printf("%d\n",k+1);
	// printf("%f\n",f<<2);
	printf("%d\n",a%b);
	printf("%lf\n",fmod(f,g));
	return 0;
}

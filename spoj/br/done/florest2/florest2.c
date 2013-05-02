#include <stdio.h>
#include <math.h>
int main()
{
	int P, x, A=0;
	double y, N;
	scanf("%lf", &N);
	P = (1+sqrt(2*N-1))/2;
	for(x=2;x<=P;x++)
	{   
		y = (N+x-1)/(2*x-1);
		if(y == (int)y)
			A += 1;
	}
	printf("%d\n", A);
	return 0;
}


#include <stdio.h>
#include <math.h>
#define INF 0x3f3f3f

int main()
{
	int X[1000], Y[1000], N;
	double ret=INF, dist, dx, dy;
	int i, j;
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%d %d" ,&X[i], &Y[i]);
	}
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			dx = (double)(X[i] - X[j])/1000; 
			dy = (double)(Y[i] - Y[j])/1000;
			dist = dx*dx + dy*dy;
			if(dist < ret)
				ret = dist;
		}
	}
	if(N == 1 || N == 0)
	{
		ret = 0;
	}
	printf("%.3lf", sqrt(ret)*1000);
	return 0;
}



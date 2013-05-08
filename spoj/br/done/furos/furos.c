#include <stdio.h>
#include <math.h>
#define INF 0x3f3f3f

int main()
{
	int X[1001], Y[1001], N;
	int i, j, teste=1; 
	long long int dx, dy;
	double max, min, dist, ret;
	while(1)
	{
		scanf("%d", &N);
		if(N == 0)
			return 0;
		for(i=0;i<N;i++)
		{
			scanf("%d %d", &X[i], &Y[i]);
		}
		min = INF;
		for(i=0;i<N;i++)
		{
			max = 0;
			for(j=0;j<N;j++)
			{
				dx = (X[i]-X[j]);
				dy = (Y[i]-Y[j]);
				dist = (double)((dx*dx) + (dy*dy))/100;
				if(dist > max)
					max = dist;
			}
			if(max < min)
				min = max;
		}
		ret = 20*sqrt(min)+6;
		printf("Teste %d\n%d\n\n", teste++, (int)ret);
	}
}



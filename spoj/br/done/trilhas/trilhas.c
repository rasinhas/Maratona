#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define INF 0x3f3f3f

int main()
{
	int n, m, h, sub, des, loc, min, pmin, ant;
	int i, j;
	scanf("%d", &n);
	min = INF;
	for(i=0;i<n;i++)
	{
		sub = 0;
		des = 0;
		scanf("%d", &m);
		scanf("%d", &ant);
		for(j=0;j<m-1;j++)
		{
			scanf("%d", &h);
			if(h > ant)
				sub += h - ant;
			if(h < ant)
				des += ant - h;
			ant = h;
		}
		loc = min(sub, des);
		if(loc < min)
		{
			min = loc;
			pmin = i+1;
		}
	}
	printf("%d\n", pmin);
	return 0;
}



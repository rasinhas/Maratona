#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define INF 0x3f3f3f

using namespace std;

int main()
{
	int a, d, i;
	int at, def, num, min;
	while(scanf("%d %d", &a, &d) && a != 0)
	{
		num = 0;
		min = INF;
		for(i=0;i<a;i++)
		{
			scanf("%d", &at);
			if(at < min) min = at;
		}
		for(i=0;i<d;i++)
		{
			scanf("%d", &def);
			if(def <= min) num++;
		}
		if(num > 1)
			printf("N\n");
		else
			printf("Y\n");
	}
	return 0;
}




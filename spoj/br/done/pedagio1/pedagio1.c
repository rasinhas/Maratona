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
	int l, d, k, p;
	scanf("%d %d %d %d", &l, &d, &k, &p);
	printf("%d\n", (l*k) + ((l/d)*p));
	return 0;
}



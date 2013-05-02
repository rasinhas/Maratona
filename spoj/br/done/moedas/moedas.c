#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define rep(i,k) for((i)=0;(i)<(k);(i)++)
#define min(a,b) a < b ? a : b

int main()
{
	int pd[50100];
	int n, p, val[100], men, ret;
	int i, j;
	while(scanf("%d", &p) && p)
	{
		scanf("%d", &n);
		for(i=0;i<p+1;i++) pd[i] = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d", &val[i]);
			pd[val[i]] = 1;
		}
		for(i=1;i<p+1;i++)
		{
			if(pd[i])
				for(j=0;j<n;j++)
				{
					if(i + val[j] > p) break;
					if(pd[i+val[j]] == 0) pd[i+val[j]] = pd[i] + 1;
					else pd[i+val[j]] = min(pd[i + val[j]], pd[i] + 1);
				}
		}
		if(pd[p] == 0) printf("Impossivel\n");
		else printf("%d\n", pd[p]);
	}
	return 0;
}




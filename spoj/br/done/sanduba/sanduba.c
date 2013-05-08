#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f
#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b
#define rep(i,k) for((i)=0;(i)<(k);(i)++)
#define MOD 1300031

int main()
{
	int i, j, k, t, n;
	long long total;
	int rec[100000];
	long long int som[100000];
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%d", &n);
		for(j=0;j<n;j++)
		{
			scanf("%d", &rec[j]);
			rec[j] = rec[j]%MOD;
		}
		som[n-1] = rec[n-1];
		for(j=n-2;j>=0;j--) som[j] = (som[j+1] + rec[j])%MOD;
		total = 0;
		for(j=0;j<n;j++) total += (rec[j]*som[j])%MOD;
		printf("%lld\n", total%MOD);
	}
	return 0;
}



#include <stdio.h>

int main()
{
	int mapa[101][101];
	int i, j, n, val;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &mapa[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &val);
			mapa[i][j] += val;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ", mapa[i][j]);
		}
		printf("\n");
	}
	return 0;
}



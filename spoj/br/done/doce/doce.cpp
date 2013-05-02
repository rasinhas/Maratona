#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#define INF 0x3f3f3f3f
#define rep(i,k) for((i)=0;(i)<(k);(i)++)

using namespace std;

int main()
{
	int i, j, m, n, ret;
	while(scanf("%d %d", &m, &n) && m)
	{
		int mat[m][n+1], maxlin[m+1];
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d", &mat[i][j]);
			mat[i][n] = 0;
			mat[i][n-3] += mat[i][n-1];
			for(j=n-4;j>=0;j--)
				mat[i][j] += max(mat[i][j+2], mat[i][j+3]);
			maxlin[i] = max(mat[i][0], mat[i][1]);
		}
		maxlin[m] = 0;
		maxlin[m-3] += maxlin[m-1];
		for(i=m-4;i>=0;i--)
			maxlin[i] += max(maxlin[i+2], maxlin[i+3]);
		ret = max(maxlin[0], maxlin[1]);
		printf("%d\n", ret);
	}
	return 0;
}




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

int peso[110][110];
int mai, ret;

int main()
{
	int i, j, n, m, u, v, c;
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++) for(j=0;j<n;j++) peso[i][j] = INF;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d", &u, &v, &c);
		peso[u][v] = peso[v][u] = c;
	}
	for(i=0;i<n;i++) peso[i][i] = 0;
    for(int k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++) peso[i][j] = min(peso[i][j], peso[i][k]+peso[k][j]);
    ret = INF;
	for(i=0;i<n;i++)
	{
		mai = 0;
		for(j=0;j<n;j++) mai = max(mai, peso[i][j]);
		ret = min(mai, ret);
	}
	printf("%d\n", ret);
	return 0;
}




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

int matadj[10][10];
int vis[10], val[10], pai[10];
int n, len=0;

void dfs(int v)
{
	int i;
	vis[v] = 1;
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			pai[len] = val[i-1];
			len++;
			dfs(i);
			vis[i] = 0;
		}
	}
	if(len == n)
	{
		for(i=0;i<len;i++) printf("%d ", pai[i]);
		printf("\n");
	}
	len--;
}

bool compare(int a, int b) { return a < b; }

int main()
{
	int i, j;
	while(scanf("%d", &n) && n)
	{
		len = 0;
		for(i=0;i<n;i++) 
		{
			vis[i] = 0;
			scanf("%d", &val[i]);
		}
		sort(&val[0], &val[n], compare);
		for(i=0;i<=n;i++) for(j=1;j<=n;j++) if(i != j) matadj[i][j] = 1;
		dfs(0);
		printf("\n");
	}
	return 0;
}




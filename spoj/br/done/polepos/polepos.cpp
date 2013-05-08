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

bool compara(pair <int, int> a, pair <int, int> b) { return a.first > b.first; }

int main()
{
	vector <pair <int, int> > pilotos;
	int pos[1100];
	int i, n, p, t, inv, at, ant;
	char ret[10000];
	pair <int, int> a;
	while(scanf("%d", &n) && n)
	{
		inv = 0;
		for(i=0;i<n;i++) pos[i] = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d", &p, &t);
			a = make_pair(i+t, p);
			pilotos.push_back(a);
		}
		sort(pilotos.begin(), pilotos.end(), compara);
		sprintf(ret, "");
		while(!pilotos.empty())
		{
			at = pilotos.back().first;
			if(at == ant || at < 1 || at > n)
			{
				inv = 1;
				break;
			}
			sprintf(ret, "%s%d", ret, pilotos.back().second);
			ant = at;
			pilotos.pop_back();
			if(!pilotos.empty())
				sprintf(ret, "%s ", ret);
		}
		if(inv == 1)
			printf("-1\n");
		else
			printf("%s\n", ret);
		pilotos.clear();
	}
	return 0;
}



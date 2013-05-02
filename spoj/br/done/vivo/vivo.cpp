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
	int p, r, n, teste=1, i, j, jog, pos, cmd;
	vector <int> fila;
	while(scanf("%d %d", &p, &r) && p)
	{
		for(i=0;i<p;i++)
		{
			scanf("%d", &jog);
			fila.push_back(jog);
		}
		for(i=0;i<r;i++)
		{
			scanf("%d %d", &n, &cmd);
			for(j=0;j<n;j++)
			{
				scanf("%d", &pos);
				if(pos != cmd)
				{
					fila.erase(fila.begin()+j);
					n--;
					j--;
				}
			}
		}
		printf("Teste %d\n%d\n\n",teste++, fila.front());
		fila.clear();
	}

	return 0;
}





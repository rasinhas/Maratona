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
	int i, j, x, y, a, n, m, fail, t=1;
	int cor[110], matadj[110][110];
	queue <int> lista;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		fail = 0;
		rep(i,n) 
		{
			cor[i] = 0;
			rep(j,n) matadj[i][j] = 0;
		}
		rep(i,m)
		{
			scanf("%d %d", &x, &y);
			x--; y--;
			matadj[x][y] = 1;
			matadj[y][x] = 1;
		}
		rep(i,n)
		{
			if(cor[i] == 0) 
			{
				lista.push(i);
				cor[i] = 1;
				while(!lista.empty() && !fail)
				{
					a = lista.front();
					lista.pop();
					rep(j,n)
					{
						if(matadj[a][j])
						{
							if(!cor[j])
							{
								cor[j] = (cor[a]%2)+1;
								lista.push(j);
							}
							else if(cor[j] != (cor[a]%2)+1) 
							{
								fail = 1;
								break;
							}
						}
					}
				}
			}
			if(fail) break;
		}
		while(!lista.empty()) lista.pop();
		printf("Instancia %d\n", t++);
		if(fail)
			printf("nao\n\n");
		else
			printf("sim\n\n");
	}
	return 0;
}



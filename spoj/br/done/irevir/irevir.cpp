#include <stdio.h>
#include <queue>
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int MatAdj[2000][2000];

int main()
{
	int Used1[2000], Used2[2000];
	int N, M, V, W, P, A, B, Conexo;
	int i, j;
	queue <int> Fila1, Fila2;
	while(1)
	{
		scanf("%d %d", &N, &M);
		if(N == 0)
			return 0;
		FOR(i,N)
		{
			FOR(j,N)
			{
				MatAdj[i][j] = 0;
			}
			Used1[i] = 0;
			Used2[i] = 0;
		}
		FOR(i,M)
		{
			scanf("%d %d %d", &V, &W, &P);
			MatAdj[V-1][W-1] = 1;
			if(P == 2)
				MatAdj[W-1][V-1] = 1;
		}
		Fila1.push(0);
		Fila2.push(0);
		Used1[0] = 1;
		Used2[0] = 1;
		Conexo = 1;
		while(!Fila1.empty())
		{
			A = Fila1.front();
			Fila1.pop();
			FOR(j,N)
			{
				if(MatAdj[A][j] == 1 && Used1[j] == 0)
				{
					Fila1.push(j);
					Used1[j] = 1;
				}
			}
		}
		while(!Fila2.empty())
		{
			B = Fila2.front();
			Fila2.pop();
			FOR(j,N)
			{
				if(MatAdj[j][B] == 1 && Used2[j] == 0)
				{
					Fila2.push(j);
					Used2[j] = 1;
				}
			}
		}
		FOR(j,N)
		{
			if(Used1[j] == 0 || Used2[j] == 0)
				Conexo = 0;
		}
		if(Conexo == 1)
			printf("1\n");
		else
			printf("0\n");
	}
}



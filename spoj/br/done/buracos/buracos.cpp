#include <stdio.h>
#include <vector>
#include <queue>
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

vector<int> LisAdj[3500];
vector<int> LisAdjT[3500];

int main()
{
	int Used1[3500], Used2[3500];
	int N, M, V, W, P, A, B, Conexo, teste=1, len, p;
	int i, j;
	queue <int> Fila1, Fila2;
	while(1)
	{
		scanf("%d %d", &N, &M);
		if(N == 0)
			return 0;
		FOR(i,N)
		{
            LisAdj[i].clear();
            LisAdjT[i].clear();
			Used1[i] = 0;
			Used2[i] = 0;
		}
		FOR(i,M)
		{
			scanf("%d %d", &V, &W);
		    LisAdj[V-1].push_back(W-1);
		    LisAdjT[W-1].push_back(V-1);
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
            len = LisAdj[A].size();
			FOR(j,len)
			{
                p = LisAdj[A][j];
				if(Used1[p] == 0)
				{
					Fila1.push(p);
					Used1[p] = 1;
				}
			}
		}
		while(!Fila2.empty())
		{
			B = Fila2.front();
			Fila2.pop();
            len = LisAdjT[B].size();
			FOR(j,len)
			{
                p = LisAdjT[B][j];
				if(Used2[p] == 0)
				{
					Fila2.push(p);
					Used2[p] = 1;
				}
			}
		}
		FOR(j,N)
		{
			if(Used1[j] == 0 || Used2[j] == 0)
				Conexo = 0;
		}
        printf("Teste %d\n", teste++);
		if(Conexo == 1)
			printf("S\n\n");
		else
			printf("N\n\n");
	}
}




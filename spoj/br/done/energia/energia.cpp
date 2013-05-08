#include <iostream>
#include <stdio.h>
#include <queue>
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int main()
{
	int MatAdj[100][100];
	int i, j, E, L, X, Y, A, teste=1;
	int Used[100];
	int Conexo;
	queue <int> Fila;
	while(1)
	{
		scanf("%d %d", &E, &L);
		if(E == 0)
			return 0;
		FOR(i,100)
		{
			FOR(j,100)
			{
				MatAdj[i][j] = 0;
			}
			Used[i] = 0;
		}
		FOR(i,L)
		{
			scanf("%d %d", &X, &Y);
			MatAdj[X-1][Y-1] = 1;
			MatAdj[Y-1][X-1] = 1;
		}
		Fila.push(1);
		Used[1] = 1;
		while(!Fila.empty())
		{
			A = Fila.front();
			Fila.pop();
			FOR(i,E+1)
			{
				if(MatAdj[A][i] == 1 && Used[i] == 0)
				{
					Fila.push(i);
					Used[i] = 1;
				}
			}
		}
		printf("Teste %d\n", teste);
		teste++;
		Conexo = 1;
		FOR(i,E)
		{
			if(Used[i] == 0)
			{
				Conexo = 0;
				break;
			}
		}
		if(Conexo == 1)
			printf("normal\n\n");
		if(Conexo == 0)
			printf("falha\n\n");
	}
}



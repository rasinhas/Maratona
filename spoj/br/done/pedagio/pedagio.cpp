#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int C, E, L, P, X, Y;
	int adj[50][50];
	int i, j, n, teste=1;
	queue <int> fila;
	int usados[50];
	int distancia[50];
	while(1)
	{
		scanf("%d %d %d %d", &C, &E, &L, &P);
		if(C == 0)
			return 0;
		L--;
		for(i=0;i<C;i++)
		{
			for(j=0;j<C;j++)
			{
				adj[i][j] = 0;
			}
			usados[i] = 0;
			distancia[i] = 1000;
		}
		for(i=0;i<E;i++)
		{
			scanf("%d %d", &X, &Y);
			adj[X-1][Y-1] = 1;
			adj[Y-1][X-1] = 1;
		}
		fila.push(L);
		distancia[L] = 0;
		usados[L] = 1;
		while(!fila.empty())
		{
			n = fila.front();
			fila.pop();
			for(i=0;i<C;i++)
			{
				if(adj[n][i] == 1 && usados[i] == 0)
				{
					fila.push(i);
					usados[i] = 1;
					distancia[i] = distancia[n] + 1;
				}
			}
		}
		printf("Teste %d\n", teste);
		teste++;
		for(i=0;i<C;i++)
		{
			if(distancia[i] <= P && distancia[i] != 0)
			{
				printf("%d ", i+1);
			}
		}
		printf("\n\n");
	}
}



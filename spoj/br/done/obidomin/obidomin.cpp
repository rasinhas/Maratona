#include <stdio.h>
#include <queue>
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int main()
{
	int N, X, Y, A, Conexo, cont[8], impcont, teste=1, i, j;
	int MatAdj[8][8];
	int Used[8];
	queue <int> Fila;

	while(1)
	{
		scanf("%d", &N);
		if(N == 0)
			return 0;
		FOR(i,8)
		{
			FOR(j,8)
			{
				MatAdj[i][j] = 0;
			}
			Used[i] = 0;
			cont[i] = 0;
		}
		impcont = 0;
		Conexo = 1;
		FOR(i,N)
		{
			scanf("%d %d", &X, &Y);
			cont[X]++;
			cont[Y]++;
			MatAdj[X][Y] = 1;
			MatAdj[Y][X] = 1;
		}
		FOR(i,7)
		{
			if(cont[i] > 0)
			{
				Used[i] = 1;
				Fila.push(i);
				break;
			}
		}
		while(!Fila.empty())
		{
			A = Fila.front();
			Fila.pop();
			FOR(i,7)
			{
				if(MatAdj[A][i] == 1 && Used[i] == 0)
				{
					Fila.push(i);
					Used[i] = 1;
				}
			}
		}
		FOR(i,7)
		{
			if(cont[i] > 0 && Used[i] == 0)
			{
				Conexo = 0;
				break;
			}
		}
		FOR(i,7)
		{
			if(cont[i]%2 != 0)
				impcont++;
		}
		printf("Teste %d\n", teste);
		teste++;
		if(impcont > 2 || Conexo == 0)
			printf("nao\n\n");
		else
			printf("sim\n\n");
	}
}



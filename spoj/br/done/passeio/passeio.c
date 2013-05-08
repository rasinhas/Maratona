#include <stdio.h>
#define FOR(i,n) for(i=0;i<n;i++)

int MatAdj[151][151];
int Visited[151];
int H[151];
int Max;

void dfs(int A, int N)
{
	int i;
	int visitou = 0;
	FOR(i,N)
	{
		if(MatAdj[A][i] == 1 && Visited[i] == 0)
		{
			Visited[i] = 1;
			dfs(i,N);
		}
		if(MatAdj[A][i] == 1 && Visited[i] == 1)
			H[A] = (H[i] >= H[A] ? H[i]+1 : H[A]);
	}
}

int main()
{
	int N, Teste=1, P, L, I, X, Y;
	int i, j;
	int Altura[151];
	while(1)
	{
		Max = 0;
		scanf("%d %d %d", &P, &L, &I);
		if(P == 0)
			return 0;
		FOR(i,P+1)
		{
			FOR(j,P+1)
				MatAdj[i][j] = 0;
			Altura[i] = 0;
			Visited[i] = 0;
			H[i] = 0;
		}
		FOR(i,P)
		{
			scanf("%d", &Altura[i+1]);
		}
		FOR(i,L)
		{
			scanf("%d %d", &X, &Y);
			if(Altura[X] > Altura[Y])
				MatAdj[X][Y] = 1;
		}
		dfs(I,P+1);
		printf("Teste %d\n%d\n\n", Teste, H[I]);
		Teste++;
	}
}



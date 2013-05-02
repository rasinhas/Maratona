#include <stdio.h>
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int main()
{
	int N, M, Mat[100][100], Soma, Max=0;
	int i, j;
	scanf("%d %d", &N, &M);
	FOR(i,N)
	{
		FOR(j,M)
		{
			scanf("%d", &Mat[i][j]);
		}
	}
	FOR(i,N)
	{
		Soma = 0;
		FOR(j,M)
		{
			Soma += Mat[i][j];
		}
		if(Soma > Max)
			Max = Soma;
	}
	FOR(i,M)
	{
		Soma = 0;
		FOR(j,N)
		{
			Soma += Mat[j][i];
		}
		if(Soma > Max)
			Max = Soma;
	}
	printf("%d", Max);
	return 0;
}



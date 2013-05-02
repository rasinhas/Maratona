#include <stdio.h>
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int main()
{
	int N, A, B, Atual, Intervalo[2], Max, MaxInt[2], Teste=1;
	int i;
	while(1)
	{
		scanf("%d", &N);
		if(N == 0)
			return 0;
		Atual = 0;
		Max = 0;
		MaxInt[0] = 0;
		MaxInt[1] = 0;
		Intervalo[0] = 1;
		Intervalo[1] = 0;
		FOR(i, N)
		{
			scanf("%d %d", &A, &B);
			Atual += (A-B);
			Intervalo[1]++;
			if(Atual < 0)
			{
				Atual = 0;
				Intervalo[0] = i+2;
				Intervalo[1] = i+1;
			}
			if(Atual > Max)
			{
				Max = Atual;
				MaxInt[0] = Intervalo[0];
				MaxInt[1] = Intervalo[1];
			}
			else if(Max == Atual)
			{
				if(MaxInt[1] - MaxInt[0] < Intervalo[1] - Intervalo[0])
				{
					MaxInt[0] = Intervalo[0];
					MaxInt[1] = Intervalo[1];
				}
			}
		}
		printf("Teste %d\n", Teste);
		if(Max == 0)
			printf("nenhum\n\n");
		else
			printf("%d %d\n\n", MaxInt[0], MaxInt[1]);
		Teste++;
	}
}



#include <stdio.h>
#define FOR(i,n) for(i=0;i<n;i++)

int main()
{
	int N, J, C, Max;
	int i, j, f = 0;
	int Pontuacao[25];
	int TopoMonte[25];
	int Descarte[15];
	int Jogador = 0;
	while(1)
	{
		scanf("%d %d", &N, &J);
		if(N == 0)
			return 0;
		Jogador = 0;
		Max = 0;
		FOR(i,25)
		{
			Pontuacao[i] = 0;
			TopoMonte[i] = 0;
		}
		FOR(i,15)
		{
			Descarte[i] = 0;
		}
		FOR(i,N)
		{
			f = 0;
			scanf("%d", &C);
			FOR(j, J)
			{
				if(TopoMonte[j] == C)
				{
					//					printf("roubei\n");
					if(j != Jogador)
					{
						TopoMonte[j] = 0;
						TopoMonte[Jogador] = C;
						Pontuacao[Jogador] += Pontuacao[j] + 1;
						Pontuacao[j] = 0;
						f = 1;
						break;
					}
					else
					{
						Pontuacao[Jogador] += 1;
						f = 1;
						break;
					}
				}
			}
			if(f == 1)
				continue;
			else if(Descarte[C] == 1)
			{
				//				printf("peguei descarte\n");
				TopoMonte[Jogador] = C;
				Pontuacao[Jogador] += 2;
				Descarte[C] = 0;
			}
			else
			{
				//				printf("descartei\n");
				Descarte[C] = 1;
				if(Jogador == J-1)
					Jogador = 0;
				else
					Jogador += 1;
			}
		}
		FOR(i, J)
		{
			if(Pontuacao[i] > Max)
				Max = Pontuacao[i];
		}
		printf("%d ", Max);
		FOR(i, J)
		{
			if(Pontuacao[i] == Max)
				printf("%d ", i+1);
		}
		printf("\n");
	}
}



#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f

int main()
{
	int Vizinhos2[1000];
	char Vizinhos[100000];
	int len, min, cont;
	int N, P;
	int i, j, k;
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		min = INF;
		scanf("%d", &P);
		for(j=0;j<P;j++)
		{
			cont = 0;
			getchar();
			scanf("%[^\n]s",Vizinhos);
			len = strlen(Vizinhos);
			for(k=0;k<len;k++)
			{
				if(Vizinhos[k] == ' ')
					cont++;
			}
			Vizinhos2[j] = cont+1;
			if(Vizinhos2[j] < min)
			{
				min = Vizinhos2[j];
			}
		}
		for(j=0;j<P;j++)
		{
			if(Vizinhos2[j] == min)
				printf("%d ", j+1);
		}
		printf("\n");
	}
	return 0;
}



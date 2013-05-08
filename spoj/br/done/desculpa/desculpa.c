#include <stdio.h>

int main()
{
	int C, F;
	int i, j, teste=1, cur, old;
	int Caracteres[50], Desculpas[50];
	int dp[2][1001];
	while(1)
	{
		scanf("%d %d", &C, &F);
		if(C == 0)
			return 0;
		for(i=0;i<F;i++)
		{
			scanf("%d %d", &Caracteres[i], &Desculpas[i]);
		}
		for(i=0;i<=C;i++){
			dp[0][i] = 0;
			dp[1][i] = 0;
		}
		for(i=0;i<F;i++)
		{
			old = i%2;
			cur = (i+1)%2;
			for(j=0;j<=C;j++)
			{
				dp[cur][j] = dp[old][j];
				if(j >= Caracteres[i]){
					if(dp[old][j - Caracteres[i]] + Desculpas[i] > dp[old][j]) dp[cur][j] = dp[old][j - Caracteres[i]] + Desculpas[i];
				}
			}
		}
		printf("Teste %d\n", teste++);
		printf("%d\n\n", dp[cur][C]);
	}
}



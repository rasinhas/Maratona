#include <stdio.h>

int main()
{
	int n;
	int i, j, c, trinca, par, k, x[2], cont[14], pontos, teste=1;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<14;j++)
		{
			cont[j] = 0;
		}
		for(j=0;j<5;j++)
		{
			scanf("%d", &c);
			cont[c]++;
		}
		k = 0;
		pontos = 0;
		par = 0;
		trinca = 0;
		for(j=1;j<14;j++)
		{
			if(cont[j] == 2)
			{
				x[k]=j;
				par++;
				k++;
			}
			if(cont[j] == 3)
			{
				trinca = 1;
				pontos = j + 140;
			}
			if(cont[j] == 4)
			{
				pontos = j+ 180;
				break;
			}
			if(cont[j] == 1 && cont[j+1] == 1 && cont[j+2] == 1 && cont[j+3] == 1 && cont[j+4] == 1)
			{
				pontos = j + 200;
				break;
			}
			if(trinca == 1 && par == 1)
			{
				pontos += 20;
				break;
			}
			if(par == 1 && trinca == 0 && j == x[0])
			{
				pontos = x[0];
			}
			if(par == 2)
			{
				pontos = (2*x[0] + 3*x[1])+20;
				break;
			}
		}
		printf("Teste %d\n%d\n\n", teste++, pontos);
	}
	return 0;
}



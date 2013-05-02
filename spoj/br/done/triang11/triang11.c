#include <stdio.h>

int main()
{
	int lados[4], l[4], i;
	char tipo;
	scanf("%d %d %d", &lados[0], &lados[1], &lados[2]);
	for(i=0;i<3;i++) l[i] = lados[i]*lados[i];
	tipo = 'a';
	for(i=0;i<3;i++)
	{
		if(lados[i] >= lados[(i+1)%3]+lados[(i+2)%3])
		{
			tipo = 'n';
			break;
		}
	}
	if(tipo == 'a')
	{
		for(i=0;i<3;i++)
		{
			if(l[i] == l[(i+1)%3] + l[(i+2)%3])
			{
				tipo = 'r';
				break;
			}
		}
	}
	if(tipo == 'a')
	{
		for(i=0;i<3;i++)
		{
			if(l[i] > l[(i+1)%3] + l[(i+2)%3])
			{
				tipo = 'o';
				break;
			}
		}
	}
	printf("%c\n", tipo);
	return 0;
}

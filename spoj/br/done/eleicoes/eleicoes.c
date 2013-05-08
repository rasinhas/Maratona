#include <stdio.h>

int compare(const void * a, const void * b)
{  
	return (*(int*)a - *(int*)b);  
}   

int main()
{
	int n, i, num;
	int max, vencedor, auxw, auxv;
	int votos[100001];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &num);
		votos[i] = num;
	}
	qsort(votos, (size_t)n, sizeof(int), compare );
	max = 0;
	vencedor = votos[0];
	auxw = votos[0];
	auxv = 1;
	for(i=1;i<n;i++)
	{
		if(votos[i] == auxw)
			auxv++;
		else 
		{
			if(auxv > max)
			{
				max = auxv;
				vencedor = auxw;
			}
			auxw = votos[i];
			auxv = 1;
		}
	}
	if(auxv > max)
	{
		max = auxv;
		vencedor = auxw;
	}
	printf("%d\n", vencedor);
	return 0;	
}



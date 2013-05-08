#include <stdio.h>
int main()
{
	int N, atual, anterior=0, T=0, i, inicial;
	scanf("%d", &N);
	scanf("%d", &inicial);
	for(i=1;i<N;i++)
	{
		scanf("%d", &atual);
		if(atual - anterior <= 10)
			T += atual - anterior;
		else
			T += 10;
		anterior = atual;
	}
	printf("%d\n", T+10-inicial);
	return 0;
} 



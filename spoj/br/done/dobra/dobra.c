#include <stdio.h>
int main()
{
	int i, N, k = 1, T = 1;
	int D[16] = {4, 9, 25, 81, 289, 1089, 4225, 16641, 66049, 263169, 1050625, 4198401, 16785409, 67125249, 268468225, 1073807361};
	while(1)
	{   
		scanf("%d", &N);
		if(N == -1)
			return 0;
		printf("Teste %d\n%d\n\n", T, D[N]);
		T++;
	}
} 


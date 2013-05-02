#include <stdio.h>

int main()
{
	int N, L, C, T=0, i;
	scanf("%d", &N);
	for(i=0;i<N;i++)
	{
		scanf("%d %d", &L, &C);
		if(L > C)
			T += C;
	}
	printf("%d", T);
	return 0;
}


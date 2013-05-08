#include <stdio.h>
int main()
{
	char nome[11];
	int T, N, P, p, i;
	while(1)
	{
		scanf("%d %d", &T, &N);
		if(T == 0)
			return 0;
		P = 0;
		for(i=0;i<T;i++)
		{
			scanf("%s %d", nome, &p);
			P += p;
		}
		printf("%d\n", 3*N-P);
	}
}


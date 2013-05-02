#include <stdio.h>

int main()
{
	int vet[92], bola[91], i, N, B, j, f, dif;
	while(1)
	{
		scanf("%d %d", &N, &B);
		f = 0;
		for(i=0;i<=N;i++)
			vet[i] = 0;
		if(B == 0)
			return 0;
		for(i=0;i<B;i++)
		{
			scanf("%d", &bola[i]);
		}
		for(i=0;i<B;i++)
		{
			for(j=0;j<B;j++)
			{
				dif = bola[i]-bola[j];
				if(dif >= 0)
					vet[dif] = dif;
			}
		}
		for(i=0;i<=N;i++)
		{
			if(vet[i] != i)
			{
				f = 1;
				break;
			}
		}
		if(f == 0)
			printf("Y\n");
		else
			printf("N\n");
	}
}


#include <stdio.h>

int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int principe[2], princesa[3];
	int cartas[52];
	int i, f0, f1, minimo;
	while(1)
	{
		scanf("%d %d %d %d %d", &princesa[0], &princesa[1], &princesa[2], &principe[0], &principe[1]);
		if(princesa[0] == 0)
			return 0;
		f0 = 0;
		f1 = 0;
		minimo = 1;
		for(i=0;i<52;i++)
			cartas[i] = 0;
		cartas[principe[0]-1] = 1;
		cartas[principe[1]-1] = 1;
		qsort(princesa, 3, sizeof(int), compare);
		qsort(principe, 2, sizeof(int), compare);
		for(i=0;i<3;i++)
		{
			cartas[princesa[i]-1] = 1;
			if(principe[0] < princesa[i])
			{
				f0++;
			}
			if(principe[1] < princesa[i])
			{
				f1++;
			}
		}
		if(f0 + f1 > 3)
		{
			printf("-1\n");
		}
		else
		{
			if(f0 + f1 == 0)
				minimo = 1;
			else if((f0 == 2 || f1 == 2) && f0 + f1 == 2)
				minimo = princesa[2];
			else if(f0 + f1 == 1 || f0 + f1 == 2)
				minimo = princesa[1];
			else if(f0 == 3 || f1 == 3)
				minimo = princesa[2];
			else
				minimo = 53;
			while(cartas[minimo-1] == 1)
				minimo++;
			if(minimo > 52)
				printf("-1\n");
			else
				printf("%d\n", minimo);
		}
	}
}



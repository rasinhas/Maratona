#include <stdio.h>

int main()
{
	int N, M;
	double V;
	double P;
	while(1)
	{
		scanf("%lf %d %d", &V, &N, &M);
		if(V == 0)
			return 0;
		P = 0;
		if(N%10000 == M%10000)
			P = V*3000;
		else if(N%1000 == M%1000)
			P = V*500;
		else if(N%100 == M%100)
			P = V*50;
		else
		{
			N = N%100 - 1;
			M = M%100 - 1;
			if(N == -1)
				N = 99;
			if(M == -1)
				M = 99;
			if(N/4 == M/4)
				P = V*16;
		}
		printf("%.2lf\n", P);
	}
}



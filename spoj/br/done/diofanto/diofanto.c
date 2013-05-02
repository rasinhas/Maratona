#include <stdio.h>
#define MOD 1300031

int fat[2000001], inv[1000001];

inline int pot(int a, int b) {
	int ret = 1;
	while(b)
	{
		if (b%2 == 1) 
		{
			ret = ((long long)ret * a)%MOD;
		}
		a = ((long long)a*a)%MOD;
		b /= 2;
	}
	return ret;
}

int main()
{
	int N, C, testes, i, j;
	int INV, A;
	scanf("%d", &testes);
	fat[0] = 0;
	fat[1] = 1;
	for(i=2; i<2000001; i++)
	{
		fat[i] = ((long long)fat[i-1]*i)%MOD;
		if(i < 1000001)
			inv[i] = pot(fat[i], MOD-2);
	}
	for(i=0;i<testes;i++)
	{
		scanf("%d %d", &N, &C);
		INV = 1;
		if (C+N > MOD) 
		{
			printf("0\n");
		} 
		else
		{
			INV = ((long long)inv[N-1]*inv[C])%MOD;
			A = ((long long)fat[N+C-1]*INV)%MOD;
			printf("%d\n", A);
		}
	}
	return 0;
}





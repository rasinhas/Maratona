#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define INF 0x3f3f3f
#define MOD 1000
#define P 1500

int r[2][2];
int k[2][2];

void initmats()
{
	r[0][0] = r[1][1] = k[0][0] = k[0][1] = k[1][0] = 1;
	r[0][1] = r[1][0] = k[1][1] = 0;
}

void multrk()
{
	int aux[2][2];
	aux[0][0] = (r[0][0]*k[0][0]%MOD)+(r[0][1]*k[1][0]%MOD);
	aux[0][1] = (r[0][0]*k[0][1]%MOD)+(r[0][1]*k[1][1]%MOD);
	aux[1][0] = (r[1][0]*k[0][0]%MOD)+(r[1][1]*k[1][0]%MOD);
	aux[1][1] = (r[1][0]*k[0][1]%MOD)+(r[1][1]*k[1][1]%MOD);
	r[0][0] = aux[0][0];
	r[0][1] = aux[0][1];
	r[1][0] = aux[1][0];
	r[1][1] = aux[1][1];
}

void multkk()
{
	int aux[2][2];
	aux[0][0] = (k[0][0]*k[0][0]%MOD)+(k[0][1]*k[1][0]%MOD);
	aux[0][1] = (k[0][0]*k[0][1]%MOD)+(k[0][1]*k[1][1]%MOD);
	aux[1][0] = (k[1][0]*k[0][0]%MOD)+(k[1][1]*k[1][0]%MOD);
	aux[1][1] = (k[1][0]*k[0][1]%MOD)+(k[1][1]*k[1][1]%MOD);
	k[0][0] = aux[0][0];
	k[0][1] = aux[0][1];
	k[1][0] = aux[1][0];
	k[1][1] = aux[1][1];
}

int fib(n)
{
	initmats();
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	n -= 1;
	while(n > 0)
	{
		if(n%2 == 1)
			multrk();
		multkk();
		n /= 2;
	}
	return (r[0][0])%MOD;
}

int main()
{
	char num[1000000];
	int t, index, len, base, sol;
	int i, j;
	scanf("%d", &t);
	for(i=0;i<t;i++)
	{
		scanf("%s", num);
		len = strlen(num);
		base = 1;
		index = 0;
		for(j=len-1;j>=0;j--)
		{
			index = (index + (num[j]-48)*(base)%P)%P;
			base = (base*10)%P;
		}
		sol = fib(index);
		if(sol < 10)
			printf("0");
		if(sol < 100)
			printf("0");
		printf("%d\n", sol);
	}
	return 0;
}



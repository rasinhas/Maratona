#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define INF 0x3f3f3f

int main()
{
	char rumo9s[1010];
	int i, len, sum, grau;
	while(scanf("%s", rumo9s) && rumo9s[0] != '0')
	{
		grau = 0;
		printf("%s", rumo9s);
		do
		{
			len = strlen(rumo9s);
			sum = 0;
			for(i=0;i<len;i++)
				sum += ((int)rumo9s[i] - 48);
			if(sum%9 == 0)
			{
				grau++;
				sprintf(rumo9s,"%d",sum);
			}
		}while(sum%9 == 0 && sum != 9);
		if(grau == 0)
			printf(" is not a multiple of 9.\n");
		else
			printf(" is a multiple of 9 and has 9-degree %d.\n", grau);
	}
	return 0;
}



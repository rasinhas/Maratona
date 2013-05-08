#include <stdio.h>
#include <string.h>
int main()
{
	int i, count, val, dec, p, j, k;
	long long fat, N; 
	char num[25];
	scanf("%lld", &N);
	for(i=0;i<N;i++)
	{
		k = 1;
		fat = 1;
		val = 0;
		scanf("%s", num);
		for(j=0;j<4;j++)
		{
			if(num[j] == '!')
			{
				dec = j-1;
				break;
			}
		}
		for(j=dec;j>=0;j--)
		{
			val += k*((num[j]-'0'));
			k *= 10;
		}
		p = strlen(num);
		count = p - dec - 1;
		while(val > 1)
		{
			fat *= val;
			val -= count;
		}
		printf("%lld\n", fat);
	}
	return 0;
}



#include <stdio.h>
#include <string.h>

int main()
{
	int i, k, size, d;
	char num[1000];
	while(scanf("%d %s", &d, num)==2 && (d!=0 || num[0]!='0'))
	{
		size=strlen(num);
		for(i=0; i<size; i++)
			if(num[i]==d+'0')
				num[i]='a';
		k=0;
		while(num[k]=='0' || num[k]=='a')
			k++;
		if(k==size) printf("0");
		else
		{
			for(i=k; i<size; i++)
				if(num[i]!='a')
					printf("%c", num[i]);
		}
		printf("\n");
	}
	return 0;
}



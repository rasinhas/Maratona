#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char num[1001];
	int x, i;
	while(scanf("%s",num) != EOF)
	{
		x=0;
		if(atoi(&num[0]) == 0)
			return 0;
		for(i=strlen(num)-1;i>=0;i-=2)
			x+=(int)num[i]-48;
		for(i=strlen(num)-2;i>=0;i-=2)
			x-=(int)num[i]-48;
		if(x%11 == 0)
			printf("%s is a multiple of 11.\n",num);
		else
			printf("%s is not a multiple of 11.\n",num);

	}
	return 0;
}


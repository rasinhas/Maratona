#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	char fita[310];
	int i, j, par, len, anterior;
	while(scanf("%s", fita) != EOF)
	{
		par = 0;
		len = strlen(fita);
		for(j=0;j<(len+1)/2;j++)
		{
			anterior = 0;
			for(i=1;i<len;i++)
			{
				if(fita[i]+fita[anterior] == 149 || fita[i]+fita[anterior] == 137)	
				{
					fita[i] = fita[anterior] = '0';
					par++;
					break;
				}
				if(fita[i] != '0')
				{
					anterior = i;
				}
			}
		}
		printf("%d\n", par);
	}
	return 0;
}


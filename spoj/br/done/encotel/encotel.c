#include <stdio.h>
#include <string.h>
#define FOR(i,n) for(i=0;i<n;i++)

int main()
{
	int i, len;
	char Tel[31];
	while(scanf("%s", Tel) != EOF)
	{
		len = strlen(Tel);
		FOR(i,len)
		{
			if(Tel[i] < 65)
				printf("%c", Tel[i]);
			else if(Tel[i] < 81)
				printf("%d", 2+(Tel[i]-65)/3);
			else if(Tel[i] < 90)
				printf("%d", 2+(Tel[i]-66)/3);
			else
				printf("9");
		}
		printf("\n");
	}
	return 0;
}



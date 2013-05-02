#include <stdio.h>
#include <string.h>

int main()
{
	char frase[1051];
	int i, len, f = 0;
	while(1)
	{
		scanf("%[^\n]c", frase);
		getchar();
		if(frase[0] == '*')
		{
			return 0;
		}
		len = strlen(frase);
		f = 0;
		for(i=0;i<len;i++)
		{
			if(frase[i] == ' ' && frase[i+1] != frase[0] && frase[i+1] != frase[0]+32 && frase[i+1] != frase[0]-32 && frase[i+1] != 0)
			{
				f = 1;
				break;
			}
		}
		if(f == 0)
			printf("Y\n");
		else
			printf("N\n");
	}
}


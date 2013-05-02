#include <stdio.h>
#include <string.h>

using namespace std;

int hash(char c)
{
	if(c == 'W')
		return 64;
	else if(c == 'H')
		return 32;
	else if(c == 'Q')
		return 16;
	else if(c == 'E')
		return 8;
	else if(c == 'S')
		return 4;
	else if(c == 'T')
		return 2;
	else
		return 1;
}

int main()
{
	int i, tempo, len, cont;
	char jingle[210];
	while(scanf("%s", jingle) && jingle[0] != '*')
	{
		len = strlen(jingle);
		cont = 0;
		for(i=0;i<len;i++)
		{
			if(jingle[i] == '/')
			{
				if(tempo == 64)
					cont++;
				tempo = 0;
			}
			else
				tempo += hash(jingle[i]);
		}
		printf("%d\n", cont);
	}
}



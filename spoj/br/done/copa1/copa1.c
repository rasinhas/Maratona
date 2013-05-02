#include <stdio.h>
int main()
{
	char jogo[31];
	int a, b, i;
	jogo[0] = 'A';
	jogo[1] = 'B';
	jogo[2] = 'C';
	jogo[3] = 'D';
	jogo[4] = 'E';
	jogo[5] = 'F';
	jogo[6] = 'G';
	jogo[7] = 'H';
	jogo[8] = 'I';
	jogo[9] = 'J';
	jogo[10] = 'K';
	jogo[11] = 'L';
	jogo[12] = 'M';
	jogo[13] = 'N';
	jogo[14] = 'O';
	jogo[15] = 'P';
	for(i=0;i<15;i++)
	{
		scanf("%d %d", &a, &b);
		if(a > b)
			jogo[16+i] = jogo[2*i];
		else
			jogo[16+i] = jogo[2*i+1];
	}
	printf("%c\n", jogo[30]);
	return 0;
}


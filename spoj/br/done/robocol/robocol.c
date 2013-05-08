#include <stdio.h>

int main()
{
	char tab[200][200];
	char comandos[100000];
	int N, M, S;
	int i, j, posatx, posaty, achou;
	char estat;
	int figurinhas;
	while(1)
	{
		scanf("%d %d %d", &N, &M, &S);
		if(N == 0)
			return 0;
		for(i=0;i<N;i++)
		{
			getchar();
			scanf("%s", tab[i]);
		}
		scanf("%s", comandos);
		getchar();
		estat = 'N';
		figurinhas = 0;
		achou = 0;
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
			{
				if(tab[i][j] == 'N' || tab[i][j] == 'O' || tab[i][j] == 'L' || tab[i][j] == 'S')	
				{
					posatx = j;
					posaty = i;
					estat = tab[posaty][posatx];
					achou = 1;
					break;
				}
			}
			if(achou == 1)
			{
				break;
			}
		}
		for(i=0;i<S;i++)
		{
			if(comandos[i] == 'F')
			{
				if(estat == 'N' && tab[posaty-1][posatx] != '#' && posaty > 0)
					posaty--;
				else if(estat == 'S' && tab[posaty+1][posatx] != '#' && posaty < N-1)
					posaty++;
				else if(estat == 'O' && tab[posaty][posatx-1] != '#' && posatx > 0)
					posatx--;
				else if(estat == 'L' && tab[posaty][posatx+1] != '#' && posatx < M-1)
					posatx++;
				if(tab[posaty][posatx] == '*')
				{
					tab[posaty][posatx] = '.';
					figurinhas++;
				}
			}
			if(comandos[i] == 'D')
			{
				if(estat == 'N')
					estat = 'L';
				else if(estat == 'S')
					estat = 'O';
				else if(estat == 'O')
					estat = 'N';
				else if(estat == 'L')
					estat = 'S';
			}
			if(comandos[i] == 'E')
			{
				if(estat == 'N')
					estat = 'O';
				else if(estat == 'S')
					estat = 'L';
				else if(estat == 'O')
					estat = 'S';
				else if(estat == 'L')
					estat = 'N';
			}
		}
		printf("%d\n", figurinhas);
	}
}



#include <stdio.h>
#define INF 0x3f3f3f

typedef struct aluno{
	char nome[21];
	int nota;
}aluno;

int main()
{
	int N;
	aluno lista[100];
	int min, inst=1, infeliz, i, j;
	while(scanf("%d", &N) != EOF)
	{
		min = INF;
		for(i=0;i<N;i++)
		{
			scanf("%s %d", lista[i].nome, &lista[i].nota);
			if(lista[i].nota == min)
			{
				for(j=0;j<20;j++)
				{
					if(lista[i].nome[j] > lista[infeliz].nome[j])
					{
						infeliz = i;
						break;
					}
					if(lista[i].nome[j] < lista[infeliz].nome[j])
					{
						break;
					}
				}
			}
			if(lista[i].nota < min )
			{
				min = lista[i].nota;
				infeliz = i;
			}
		}
		printf("Instancia %d\n%s\n\n", inst++, lista[infeliz].nome);
	}
}



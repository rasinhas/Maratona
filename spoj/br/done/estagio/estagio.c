#include <stdio.h>
#define MAX_ALUNOS 1000

struct
{
	int codigo, media;
} alunos[MAX_ALUNOS];

int main()
{
	int i, indice_melhor, n, maior_media;
	int turma=1;
	scanf("%d", &n);
	while (n > 0)
	{
		for (i = 0; i < n; i++)
			scanf("%d %d", &alunos[i].codigo, &alunos[i].media);
		maior_media = 0;
		indice_melhor = 0;
		for (i = 0; i < n; i++)
		{
			if (alunos[i].media >= maior_media)
			{
				maior_media = alunos[i].media;
				indice_melhor = i;
			}
		}
		printf("Turma %d\n", turma++);
		for(i=0;i<n;i++)
		{
			if(alunos[i].media == maior_media)
			{
				printf("%d ", alunos[i].codigo);
			}
		}
		printf("\n\n");
		scanf("%d", &n);
	}
	return 0;
}



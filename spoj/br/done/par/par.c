#include <stdio.h>

int main(){
	int jogos, a, b, teste=1, i; 
	char jogador1[11], jogador2[11];
	while(1)
	{
		scanf("%d", &jogos);
		if(jogos == 0) 
		{
			return 0;
		}
		scanf("%s %s", jogador1, jogador2);
		printf("Teste %d\n", teste++);
		for(i=0;i<jogos;i++)
		{
			scanf("%d%d", &a, &b);
			if((a+b)%2 == 0)
				printf("%s\n", jogador1);
			else
				printf("%s\n", jogador2);
		}
	}
	return 0;
}


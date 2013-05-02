#include <stdio.h>

int main()
{
	int i, a, b, alice[10000], beatriz[10000], AliceRepetidas, BeatrizRepetidas, Repetidas, atual, podeTrocar;
	while(1)
	{
		AliceRepetidas = 0;
		BeatrizRepetidas = 0;
		Repetidas = 0;
		atual = 0;
		scanf("%d", &a);
		scanf("%d", &b);
		if(a == 0 && b == 0) return 0;
		for(i=0;i<a;i++)
		{
			scanf("%d", &alice[i]);
			if( i != 0 && alice[i] == alice[i-1]) AliceRepetidas++;
		}
		for(i=0;i<b;i++)
		{
			scanf("%d", &beatriz[i]);
			if( i != 0 && beatriz[i] == beatriz[i-1])
				BeatrizRepetidas++;
			else
			{
				while(alice[atual] < beatriz[i])
					atual++;
				if(atual < a && alice[atual] == beatriz[i])
					Repetidas++;
			}
		}
		podeTrocar = (a - AliceRepetidas < b - BeatrizRepetidas) ? a - AliceRepetidas - Repetidas : b - BeatrizRepetidas - Repetidas; 
		printf("%d\n", podeTrocar); 
	}
}  



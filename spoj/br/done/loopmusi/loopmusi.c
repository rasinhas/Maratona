#include <stdio.h>

int main()
{
	int N;
	int Picos, Inicio, Fim, Aux;
	int i;
	int Deriv[10000];

	while(1)
	{
		scanf("%d", &N);
		if(N == 0)
			return 0;
		for(i=0;i<N;i++)
			Deriv[i] = 0;
		Picos = 0;
		scanf("%d", &Inicio);
		Aux = Inicio;
		for(i=1;i<N;i++)
		{
			scanf("%d", &Fim);
			Deriv[i-1] = Fim - Aux;
			Aux = Fim;
		}
		Deriv[N-1] = Inicio - Fim;
		for(i=0;i<N-1;i++)
		{

			if(Deriv[i] * Deriv[i+1] < 0)
				Picos++;
		}
		if(Deriv[0] * Deriv[N-1] < 0)
			Picos++;
		printf("%d\n", Picos);
	}
}



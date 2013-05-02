#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define rep(i,k) for((i)=1;(i)<=(k);(i)++)

int main()
{
	int n, i, cont, ciclo, k, aux;
	int vet[100000];
	while(scanf("%d", &n) && n)
	{
		cont = 0;
		rep(i,n)
			scanf("%d", &vet[i]);
		rep(i,n)
		{
			ciclo = 1;
			k = i;
			while(vet[k] != i && vet[k])
			{
				ciclo++;
				aux = vet[k];
				vet[k] = 0;
				k = aux;
			}
			vet[k] = 0;
			cont += ciclo - 1;
		}
		if(cont%2 == 1)
			printf("Marcelo\n");
		else
			printf("Carlos\n");
	}
	return 0;
}



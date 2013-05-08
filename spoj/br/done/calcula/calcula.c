#include <stdio.h>

int main()
{
	int n, b, i, soma, teste=1;
	while(1)
	{
		scanf("%d", &n);
		soma = 0;
		if(n == 0)
			return 0;
		for(i=0;i<n;i++)
		{ 
			scanf("%d",&b);
			soma += b;
		}           
		printf("Teste %d\n%d\n\n",teste, soma);
		teste++;
	}
}


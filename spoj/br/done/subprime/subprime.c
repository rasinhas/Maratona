#include <stdio.h>

int main()
{
	int i, n, b, saldo[20], devedor, recebedor, valor, possivel;
	while(1)
	{
		possivel = 1;
		scanf("%d", &b);
		scanf("%d", &n);
		if(b == 0 && n == 0) 
			return 0;
		for(i=0;i<b;i++) 
			scanf("%d", &saldo[i]);
		for(i=0;i<n;i++)
		{
			scanf("%d", &devedor);
			scanf("%d", &recebedor);
			scanf("%d", &valor);
			saldo[devedor-1] -= valor;
			saldo[recebedor-1] += valor;
		}
		for(i=0;i<b;i++)
		{
			if(saldo[i] < 0)
			{
				possivel = 0;
				break;
			}
		}
		if(possivel == 1) 
			printf("S\n");
		else 
			printf("N\n");
	}
}


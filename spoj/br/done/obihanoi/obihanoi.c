#include <stdio.h>

int main()
{
	int discos, movimentos, i, teste=1;
	while(1)
	{
		movimentos = 1;
		scanf("%d", &discos);
		if(discos == 0)
			return 0;
		for(i=0;i<discos;i++)
			movimentos *= 2;
		printf ("Teste %d\n",teste);
		teste++;
		printf ("%d \n\n",movimentos-1);
	}
}




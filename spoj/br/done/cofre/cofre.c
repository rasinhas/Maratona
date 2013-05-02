#include <stdio.h>
int main()
{
	int n, J, Z, dif, i, teste=1; 
	while(1)
	{
		scanf("%d", &n);
		if(n == 0)
		{
			return 0;
		}
		dif = 0;
		printf("Teste %d\n", teste++);
		for(i=0; i<n; i++)
		{ 
			scanf("%d%d", &J, &Z);  
			dif += J - Z;
			printf("%d\n", dif);  
		}
		printf("\n");  
	}
	return 0;
}


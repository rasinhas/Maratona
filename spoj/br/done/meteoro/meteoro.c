#include <stdio.h>                                                                  
int main()
{
	int X1, Y1, X2, Y2, X, Y, i, teste=1, dentro, meteoros;
	while(1)
	{
		dentro = 0;
		scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
		if(X1 == 0 && Y1 == 0 && X2 == 0 && Y2 == 0)
		{
			return 0;                                                               
		}                                                                           
		scanf( "%d", &meteoros);
		for(i=0;i<meteoros;i++)
		{
			scanf( "%d%d", &X, &Y );
			if(X >= X1 && X <= X2 && Y <= Y1 && Y >= Y2)
			{
				dentro++;
			}
		}
		printf("Teste %d\n%d\n\n", teste, dentro);
		teste++;
	}                                                                               
	return 0;                                                                       
}


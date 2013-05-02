#include <stdio.h>

int main()
{
	int n, i, R=0, A, F;
	scanf("%d", &A);
	scanf("%d", &n);                                                                
	for(i=0;i<n;i++)                                                                
	{   
		scanf("%d", &F);
		if(A*F >= 40000000)
			R++;
	}
	printf("%d", R);                                                                
	return 0;                                                                       
}


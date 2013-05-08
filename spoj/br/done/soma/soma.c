#include <stdio.h>

int main()                                                                          
{                                                                                   
	int n, x, a=0, i;                                                               
	scanf("%d", &n);                                                                
	for(i=0;i<n;i++)                                                                
	{                                                                               
		scanf("%d", &x);                                                            
		a += x;                                                                     
	}                                                                               
	printf("%d", a);                                                                
	return 0;                                                                       
}


#include <stdio.h>

int f91(int n) 
{   
	if(n<=100) 
		return 91;                                                      
	if(n>=101)                                                                      
		return n-10;                                                                
}   

int main()
{       
	int x[250000], i;                                                               
	for(i=0;i<250000;i++)                                                           
	{                                                                               
		scanf("%d", &x[i]);                                                         
		if(x[i] == 0)                                                               
			break;                                                                  
	}
	i = 0;                                                                          
	while(x[i] != 0)                                                                
	{
		printf("f91(%d) = %d\n", x[i], f91(x[i]));
		i++;
	}
	return 0;
}



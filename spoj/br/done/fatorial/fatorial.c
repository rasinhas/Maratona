#include <stdio.h>

int ex(int a, int b)
{   
	int i, k=1;
	for(i=1;i<=b;i++)
	{
		k *= a;
	}   
	return k; 
}   

int a(n)
{
	int x[10];
	if(n<=1)
	{ 
		return 1;
	}
	x[0]=1; x[1]=1; x[2]=2; x[3]=6; x[4]=4; x[5]=4; x[6]=4; x[7]=8; x[8]=4; x[9]=6;
	return 6*(x[n%10]*ex(3,((n/5)%4))*a(n/5))%10;
}       

int main()
{
	int i, entrada, inst=1, k;
	while(scanf("%d", &entrada) != EOF)
	{   
		printf("Instancia %d\n%d\n\n", inst, a(entrada));
		inst++;
	}   
	return 0;
}


#include <stdio.h>
int main()
{
	int N, A, L, P;
	scanf("%d %d %d %d", &N, &A, &L, &P);
	if(N > A)
		printf("N");
	else if(N > L)
		printf("N");
	else if(N > P)
		printf("N");
	else
		printf("S");
	return 0;
}



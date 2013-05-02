#include <stdio.h>
int main()
{
	int L, A, P, R;
	scanf("%d%d%d%d",&L, &A, &P, &R);
	if (L*L + A*A + P*P <= 4*R*R)
		printf("S");
	else 
		printf("N");
	return 0;                                                                       
}


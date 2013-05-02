#include <stdio.h>

int main()
{
	long long int RET = 0;
	int N, P, Q, R, S, X, Y, i, j, k, A[100002], B[100002];
	scanf("%d %d %d %d %d %d %d %d %d", &N, &P, &Q, &R, &S, &X, &Y, &i, &j);
	for(k=1;k<N+1;k++)
	{
		A[k] = (P*i + Q*k)%X;
		B[k] = (R*k + S*j)%Y;
		RET += (A[k]*B[k]);
	}
	printf("%lld\n", RET);
	return 0;
}


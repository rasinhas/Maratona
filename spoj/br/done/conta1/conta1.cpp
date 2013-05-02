#include <stdio.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	if(N <= 10)
		printf("7");
	else if(N <= 30)
		printf("%d", N-3);
	else if(N <= 100)
		printf("%d", 2*N-33);
	else
		printf("%d", 5*N - 333);
	return 0;
}





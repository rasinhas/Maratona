#include <stdio.h>

using namespace std;

int main()
{
	int A;
	scanf("%d", &A);
	if(A%76 < 10)
		printf("%d", A-A%76+10);
	else
		printf("%d", A+86-A%76);
	return 0;
}



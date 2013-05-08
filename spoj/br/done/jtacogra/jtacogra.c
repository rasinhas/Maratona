#include <stdio.h>

int main()
{
	int n, i, T, V, R=0;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d", &T, &V);
		R += T*V;
	}
	printf("%d", R);
	return 0;
}




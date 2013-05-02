#include <stdio.h>
#include <stdlib.h>

int compara(const void *i, const void *j) { return *((int *)i)-*((int *)j); }

int main()
{
	int x[1010], y[1010], s;
	int i, teste=1;
	while(scanf("%d", &s) && s)
	{
		for(i=0;i<s;i++)
		{
			scanf("%d %d", &x[i], &y[i]);
		}
		qsort(x, s, sizeof(int), compara);
		qsort(y, s, sizeof(int), compara);
		printf("Teste %d\n%d %d\n\n", teste++, x[s/2], y[s/2]);
	}
	return 0;
}



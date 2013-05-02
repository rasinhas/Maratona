#include <stdio.h>

int main()
{
	int i, n, c, atual=0, saiu, entrou;
	char ans = 'N';

	scanf("%d", &n);
	scanf("%d", &c);
	for(i=0;i<n;i++)
	{
		scanf("%d", &saiu);
		scanf("%d", &entrou);
		atual = atual + entrou - saiu;
		if(atual > c)
			ans = 'S';
	}
	printf("%c", ans);
	return 0;
}



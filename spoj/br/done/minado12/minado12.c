#include <stdio.h>

int main()
{
	int minas[53], campo[53];
	int i, n;
	scanf("%d", &n);
	for(i=1;i<=n;i++) scanf("%d", &minas[i]);
	minas[0] = 0; minas[n+1] = 0;
	for(i=1;i<=n;i++) campo[i] = minas[i-1] + minas[i] + minas[i+1];
	for(i=1;i<=n;i++) printf("%d\n", campo[i]);
	return 0;
}

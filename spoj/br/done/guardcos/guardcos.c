#include <stdio.h>

int main()
{
	int d, vf, vg;
	while(scanf("%d %d %d", &d, &vf, &vg) != EOF)
	{
		if(144*(vg*vg) >= (144+d*d)*(vf*vf)) printf("S\n");
		else printf("N\n");
	}
	return 0;
}

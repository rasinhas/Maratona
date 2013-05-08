#include <stdio.h>

int main()
{
	int a, b, c, x, y, z, dl, dc, dh, max;
	scanf("%d %d %d %d %d %d", &a,&b,&c,&x,&y,&z);
	dl = x/a;
	dc = y/b;
	dh = z/c;
	if(dh < 0 || dc < 0 || dl < 0) { max = 0;}
	else { max = dl*dc*dh;}
	printf("%d\n", max);
	return 0;
}

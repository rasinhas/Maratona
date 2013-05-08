#include <stdio.h>

int main()
{
	double e, val;
	int i, n;
	char c;
	scanf("%d", &n);
	val = 1;
	for(i=0;i<n;i++)
	{
		scanf("%lf %c", &e, &c);
		if(c == '/') { val /= e;}
		if(c == '*') { val *= e;}
	}
	printf("%.0lf\n", val);
	return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y

int gcd(int a, int b)
{
	int r;
	r = a%b;
	while(r > 0)
	{
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}

int inv(int b, int a)
{
	int i;
	for(i=1;i<a;i++) if((i*b)%a == 1) return i;
}

int main()
{
	int t, a, b, ka, kb, mdc, total;
	scanf("%d %d %d", &t, &a, &b);
	mdc = gcd(max(a,b), min(a,b));
	total = a;
	a = max(a,b)/mdc;
	b = min(total,b)/mdc;
	t = t/mdc;
	kb = ((t%a)*inv(b,a))%a;
	ka = (t-b*kb)/a;
	if(ka > 0 && kb > 0) total = t*mdc;
	if(ka < 0) total = min((ka + b)*a*mdc, kb*b*mdc);
	if(kb < 0) total = min((kb + a)*b*mdc, ka*a*mdc);
	printf("%d\n", total);
	return 0;
}





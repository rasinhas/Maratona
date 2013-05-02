#include <iostream>
#include <cstdio>
#include <string.h>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int acc[10000001];
const long long limit = 100000000000000;

bool is_palindrome(long long v)
{
    int l;
    char a[100], ar[100];
    sprintf(a,"%lld",v);
    sprintf(ar,"%lld",v);
    l = strlen(a);
    reverse(ar,ar+l);
    if(!strcmp(a,ar)) return 1;
    return 0;
}

void precalc()
{
    for(long long i=1;i*i<=100000000000000ll;i++) if(is_palindrome(i) && is_palindrome(i*i)) acc[i] = 1;
    for(long long i=1;i<=10000000ll;i++) acc[i] += acc[i-1];
}

int main()
{
    int n, l2, r2;
    long long l, r;
    precalc();
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&l,&r);
        l2 = floor(sqrt(l-1));
        r2 = floor(sqrt(r));
        printf("Case #%d: %d\n", i+1, acc[r2]-acc[l2]);
    }
    return 0;
}

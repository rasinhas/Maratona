#include <iostream>
#include <ctype.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

long long prime[200000]; int nprimes;
void find_primes(int n) {
    nprimes = 1; prime[0] = 2; bool is_prime;
    for(int k=3;k<=n;k+=2) {
        is_prime = true;
        for(int j=0; j<nprimes && prime[j]*prime[j] <= k;++j)
            if (k%prime[j] == 0) {is_prime = false; break;}
            if ( is_prime ) prime[nprimes++] = k;
    }
}

long long p[20000]; int e[20000]; int k;
void factor(int n) {
    k = 0;
    for(int j=0; prime[j]*prime[j] <= n; ++j) if ( n%prime[j]==0 ) {
        p[k] = prime[j]; e[k] = 0;
        while ( n%prime[j]==0 ) { n/=prime[j]; e[k]++; }
        ++k;
    }
    if (n!=1) { p[k]=n; e[k] =1; ++k;}
}



int main()
{
    long long n, i;
    long long ret;
    find_primes(100000);
    while(scanf("%lld", &n) != EOF)
    {
        factor(n);
        ret = n;
        for(i=0;i<k;i++)
        {
            ret = ret/p[i];
            ret = ret*(p[i]-1);
        }
        ret /= 2;
        printf("%lld\n",ret);
    }
    return 0;
}

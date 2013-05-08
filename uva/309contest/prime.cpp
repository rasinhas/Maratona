#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 10000001, SIZE = MAXN/16+1;
const int MAX_PRIMES = 685000; // 1.26 * MAXN / log(MAXN);
char mark[SIZE]; // ( mark[n>>4]&(1<<((n>>1)&7)) ) == 0 se 2*n+1 eh primo
char is_prime[MAXN];
int primes[MAX_PRIMES], cnt_primes;
void sieve( int N ) {
    int i, j;
    for ( i = 3; i*i <= N; i += 2 ) if ( ( mark[i>>4] & (1<<((i>>1)&7)) ) == 0 )
        for ( j = i*i; j <= N; j += i<<1 ) mark[j>>4] |= ( 1<<((j>>1)&7) );
        cnt_primes = 0;
        primes[cnt_primes++] = 2;
        for ( i = 3; i <= N; i += 2 ) if ( (mark[i>>4]&(1<<((i>>1)&7))) == 0 )
            primes[cnt_primes++] = i;
            for(int i=0;i<cnt_primes;i++) is_prime[primes[i]] = 1;
}

int main()
{
    int mai, val, p, pnt, aux, i, lim;
    string str;
    sieve(200000);
    while((cin >> str) && (str != "0"))
    {
        pnt = str.size()-1;
        mai = 0;
        while(pnt >= 0)
        {
            p = (int)str[pnt]-'0';
            if(p == 4 || p == 6 || p == 8 || p == 0) pnt--;
            else
            {
                val = 0;
                aux = 1;
                lim = min(7,pnt+1);
                for(i=0;i<lim;i++)
                {
                    p = (int)str[pnt-i]-'0';
                    val += p*aux;
                    if(is_prime[val] && val > mai && val < 100000) mai = val;
                    aux *= 10;
                }
                pnt--;
            }
        }
        printf("%d\n",mai);
    }
    return 0;
}

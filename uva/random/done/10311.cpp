#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 100000000, SIZE = 100000001;
const int MAX_PRIMES = 50000000; // 1.26 * MAXN / log(MAXN);
char mark[SIZE]; // ( mark[n>>4]&(1<<((n>>1)&7)) ) == 0 se 2*n+1 eh primo
int primes[MAX_PRIMES], cnt_primes;
bool is_prime[SIZE];
void sieve( int N ) {
    int i, j;
    for ( i = 3; i*i <= N; i += 2 ) if ( ( mark[i>>4] & (1<<((i>>1)&7)) ) == 0 )
        for ( j = i*i; j <= N; j += i<<1 ) mark[j>>4] |= ( 1<<((j>>1)&7) );
        cnt_primes = 0;
        primes[cnt_primes++] = 2;
        for ( i = 3; i <= N; i += 2 ) if ( (mark[i>>4]&(1<<((i>>1)&7))) == 0 )
        {
            primes[cnt_primes++] = i;
            is_prime[i] = 1;
        }
}

int main()
{
    int n, i, f;
    sieve(100000000);
    while(scanf("%d", &n) != EOF)
    {
        f = 0;
        if(n%2 == 1) 
        {
            if(is_prime[n-2]) printf("%d is the sum of 2 and %d.\n", n, n-2);
            else printf("%d is not the sum of two primes!\n", n);
        }
        else
        {

            for(i=(lower_bound(primes,primes+cnt_primes,n/2)-primes)-1;i>=0;i--)
            {
                if(is_prime[n-primes[i]]) { f = 1; break;}
            }
            if(f) printf("%d is the sum of %d and %d.\n", n, primes[i], n-primes[i]);
            else printf("%d is not the sum of two primes!\n", n);
        }
    }
    return 0;
}

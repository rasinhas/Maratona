#include <stdio.h>

using namespace std;

int twin[500000];int ntwin;

const int MAXN = 20000001, SIZE = 20000001;
const int MAX_PRIMES = 20000000; // 1.26 * MAXN / log(MAXN);
char mark[SIZE]; // ( mark[n>>4]&(1<<((n>>1)&7)) ) == 0 se 2*n+1 eh primo
char is_prime[MAXN];
int primes[MAX_PRIMES], cnt_primes;
void sieve( int N ) {
    int i, j;
    ntwin = 0;
    for ( i = 3; i*i <= N; i += 2 ) if ( ( mark[i>>4] & (1<<((i>>1)&7)) ) == 0 )
        for ( j = i*i; j <= N; j += i<<1 ) mark[j>>4] |= ( 1<<((j>>1)&7) );
        cnt_primes = 0;
        primes[cnt_primes++] = 2;
        for ( i = 3; i <= N; i += 2 ) if ( (mark[i>>4]&(1<<((i>>1)&7))) == 0 )
        {
            if(i - primes[cnt_primes-1] == 2) twin[ntwin++] = i-2;
            primes[cnt_primes++] = i;
        }
            for(int i=0;i<cnt_primes;i++) is_prime[primes[i]] = 1;
}

int main()
{
    int n, i;
    sieve(20000000);
    while(scanf("%d", &n) != EOF)
    {
        printf("(%d, %d)\n",twin[n-1],twin[n-1]+2);
    }
    return 0;
}

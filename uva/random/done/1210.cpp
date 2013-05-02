#include <stdio.h>

using namespace std;

int ac[10000], pos[20000];
const int MAXN = 10000, SIZE = 10001;
const int MAX_PRIMES = 10000; // 1.26 * MAXN / log(MAXN);
char mark[SIZE]; // ( mark[n>>4]&(1<<((n>>1)&7)) ) == 0 se 2*n+1 eh primo
int primes[MAX_PRIMES], cnt_primes;
bool is_prime[SIZE];
void sieve( int N ) {
    int i, j;
    for ( i = 3; i*i <= N; i += 2 ) if ( ( mark[i>>4] & (1<<((i>>1)&7)) ) == 0 )
        for ( j = i*i; j <= N; j += i<<1 ) mark[j>>4] |= ( 1<<((j>>1)&7) );
        cnt_primes = 0;
        primes[cnt_primes++] = 2;
        ac[0] = 0;
        ac[1] = 2;
        for ( i = 3; i <= N; i += 2 ) if ( (mark[i>>4]&(1<<((i>>1)&7))) == 0 )
        {
            primes[cnt_primes++] = i;
            ac[cnt_primes] = ac[cnt_primes-1] + i;
            is_prime[i] = 1;
        }
}

int main()
{
    int i, j, n;
    sieve(10000);
    for(i=0;i<=cnt_primes;i++) for(j=i;j<=cnt_primes;j++) if(ac[j]-ac[i] < 10001) pos[ac[j]-ac[i]]++;
    while(scanf("%d", &n) && n) printf("%d\n", pos[n]);
}

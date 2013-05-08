#include <stdio.h>
#include <utility>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN = 2000001, SIZE = 2000001;
const int MAX_PRIMES = 2000000; // 1.26 * MAXN / log(MAXN);
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

/* calcula todos o primos até 10^6
   usa upper/lower_bound para encontrar
   o início e o fim do intervalo.
   percorre o intervalo e verifica qual o
   campeão.
*/
int main()
{
    int i, l, u, m, p, f, ret, n;
    int *up, *lo;
    int cnt[1001000];
    sieve(1001000);
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &l, &u);
        memset(cnt,0,sizeof(cnt));
        lo = lower_bound(primes,primes+cnt_primes,l);
        up = upper_bound(primes,primes+cnt_primes,u);
        m = 0;
        for(i=(lo-primes);i<(up-primes)-1;i++)
        {
            p = primes[i+1]-primes[i];
            cnt[p]++;
            if(cnt[p] == m) f = 1;
            if(cnt[p] > m) 
            {
                m = cnt[p];
                ret = p;
                f = 0;
            }
        }
        if(f || !m) printf("No jumping champion\n");
        else printf("The jumping champion is %d\n", ret);
    }
    return 0;
}

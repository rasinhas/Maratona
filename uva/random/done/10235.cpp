#include <stdio.h>
#include <algorithm>
#include <utility>
#include <string.h>

using namespace std;

const int MAXN = 1000000, SIZE = 1000001;
const int MAX_PRIMES = 500000; // 1.26 * MAXN / log(MAXN);
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
    int i, j, n, nrev;
    char num[100];
    sieve(1000000);
    while(scanf("%s", num) != EOF)
    {
        int len = strlen(num);
        n = atoi(num);
        reverse(num,num+len);
        nrev = atoi(num);
        if(is_prime[n])
        {
            if(is_prime[nrev] && n != nrev) printf("%d is emirp.\n", n);
            else printf("%d is prime.\n", n);
        }
        else printf("%d is not prime.\n", n);
    }
}

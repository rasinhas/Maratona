#include <iostream>
#include <cstdio>
#include <string>
#include<cstring>
#define pb push_back
#define sz size()
#define mp make_pair

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
    int n;
    sieve(10000001);
    cin >> n;
    printf("%d", primes[0]);
    for(int i=1;i<n;i++) printf(" %d", primes[i]);
    cout << endl;
    return 0;
}

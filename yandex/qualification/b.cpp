#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back

using namespace std;

const int MAXN = 100001, SIZE = MAXN/16+1;
const int MAX_PRIMES = 20000;
char mark[SIZE];
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

vector <int> pp1;

int main()
{
    int n;
    sieve(40000);
    cin >> n;
    for(int i=0;i<cnt_primes;i++)
    {
        for(int j=i;j<cnt_primes;j++)
        {
            pp1.pb(primes[i]*primes[j]+1);
            if(primes[i]*primes[j]+1 > n*n) break;
        }
    }
    sort(pp1.begin(),pp1.end());
    for(int i=4;i<=n;i++)
    {
        if(binary_search(pp1.begin(),pp1.end(),i*i)) cout << i << endl;
    }
    return 0;
}

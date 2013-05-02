#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <cstring>
#include <utility>
#include <algorithm>
#define sz size()
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

vector <pair <int,int> > factors[1000010];

const int MAXN = 1000001, SIZE = 1001000;
const int MAX_PRIMES = 400000; // 1.26 * MAXN / log(MAXN);
char mark[SIZE]; // ( mark[n>>4]&(1<<((n>>1)&7)) ) == 0 se 2*n+1 eh primo
int primes[MAX_PRIMES], cnt_primes;
bool is_prime[SIZE];
void sieve(int N) {
    int i, j;
    for (i=3;i*i<=N;i+=2) if((mark[i>>4] & (1<<((i>>1)&7))) == 0)
        for (j=i*i;j<=N;j+=i<<1) mark[j>>4]|=(1<<((j>>1)&7));
        cnt_primes = 0;
        primes[cnt_primes++] = 2;
        for(i=3;i<=N;i+=2) if((mark[i>>4]&(1<<((i>>1)&7))) == 0)
        {
            primes[cnt_primes++] = i;
            is_prime[i] = 1;
        }
}

void sieve_factorization(int maxn)
{
    int e, p;
    for(int i=0;i<cnt_primes;i++)
    {
        for(int j=primes[i];j<=maxn;j+=primes[i])
        {
            p = j;
            e = 0;
            while(p%primes[i] == 0)
            {
                p/=primes[i];
                e++;
            }
            factors[j].pb(mp(primes[i],e));
        }
    }
}

void print(int a, int b)
{
    for(int i=a;i<=b;i++)
    {
        cout << "@" << i << "--";
        for(int j=0;j<factors[i].sz;j++)
        {
            cout << factors[i][j].first << "^" << factors[i][j].second << " ";
        }
        cout << endl;
    }
}

int fexp(int n, int e)
{
    if(e == 0) return 1;
    if(e == 1) return n;
    if(e%2 == 0) return fexp((1ll * n * n)%mod,e/2);
    return (1ll * n * fexp(n,e-1))%mod;
}

int inv(int n) { return fexp(n,mod-2); }

int c[1000100];

int main()
{
    long long t, n, v, ret, d, a, p, ek, pk;
    cin >> t;
    sieve(1000000);
    sieve_factorization(1000000);
    //print(999900,1000000);
    for(int i=0;i<t;i++)
    {
        cin >> n;
        ret = 0;
        d = 1;
        memset(c,0,sizeof(c));
        for(int j=0;j<n;j++)
        {
            cin >> v;
            p = v;
            if(p < 0) p = -p;
            for(int k=0;k<factors[p].sz;k++)
            {
                pk = primes[factors[p][k].first];
                ek = factors[p][k].second;
                if(v > 0) 
                {
                    d = ((d * (c[pk]+ek+1))%mod * inv((c[pk]+1)))%mod; 
                    c[pk] = c[pk] + ek;
                }
                else
                {
                    d = ((d * (c[pk]-ek+1))%mod * inv((c[pk]+1)))%mod; 
                    c[pk] = c[pk] - ek;
                }
            }
            ret = (ret + d)%mod;
        }
        cout << "Case " << i+1 << ": " << ret << endl;
    }
    return 0;
}

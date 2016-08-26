#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long f[55];
int not_prime[11111];
int primes[11111], cp=1;

void sieve(int n)
{
    not_prime[1] = 1;
    primes[0] = 2;
    for(int i=3;i<=n;i+=2)
    {
        if(not_prime[i]) continue;
        primes[cp++] = i;
        for(int j=2*i;j*j<=n;j+=i) not_prime[j] = 1;
    }
}

long long fact[11111];

void go(int k, int n)
{
    int i=0;
    while(k > 1)
    {
        int e = 0;
        while(k%primes[i] == 0)
        {
            k /= primes[i];
            e++;
        }
        fact[primes[i++]] += f[n]*e;
    }
}

int main()
{
    int t;
    cin >> t;
    f[0] = 1; f[1] = 1;
    for(int i=2;i<42;i++) f[i] = f[i-1] + f[i-2];
    sieve(1001);
    while(t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        memset(fact,0,sizeof(fact));
        if(n == 0) go(a,0);
        if(n == 1) go(b,0);
        else 
        {
            go(a,n-2);
            go(b,n-1);
        }
        for(int i=0;i<=max(a,b);i++) if(fact[i]) cout << i << " " << fact[i] << endl;
        cout << endl;
    }
    return 0;
}

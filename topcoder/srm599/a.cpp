#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

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

class BigFatInteger
{
    public:
    int minOperations(int a, int b)
    {
        vector <pair<int,int> > fact;
        sieve(MAXN);
        int k = a, ret = 0;
        int i = 0;
        while(k!=1)
        {
            int e = 0;
            while(!(k%primes[i]))
            {
                k/=primes[i];
                e++;
            }
            if(i > cnt_primes) break;
            if(e) fact.push_back(make_pair(primes[i],e*b));
            i++;
        }
        ret = fact.size();
        int m = 0;
        for(i=0;i<fact.size();i++) m = max(fact[i].second,m);
        i = 0;
        m--;
        while(m)
        {
            m >>= 1;
            i++;
        }
        ret += i;
        return ret;
    }
};

int main()
{
    BigFatInteger a;
    cout << a.minOperations(999983,1000000) << endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#define pb push_back
#define sz size()
#define mp make_pair

using namespace std;

const int MAXN = 100001, SIZE = 100100;
const int MAX_PRIMES = 70000; // 1.26 * MAXN / log(MAXN);
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

int main()
{
    int t, n, k;
    cin >> t;
    sieve(100001);
    while(t--)
    {
        cin >> n >> k;
        int i=0;
        int e=0, me=0;
        vector <int> exp;
        while(n > 1)
        {
            int j=0;
            if(primes[i]*primes[i] > n)
            {
                exp.pb(1);
                e++;
                break;
            }
            while(!(n%primes[i]))
            {
                n/=primes[i];
                j++;
                e++;
            }
            if(j) exp.pb(j);
            i++;
        }
        if(k > e) cout << "NO" << endl;
        else 
        {
            int ok=1;
            if(exp.sz == 1 && exp[0] > k && (exp[0]-k)%2 == 1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}

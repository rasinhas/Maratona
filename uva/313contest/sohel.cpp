#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
#define pb push_back
#define INF 10000000000000

using namespace std;

vector<long long> divisors(long long n) {
    long long maxP = (long long) sqrt(n) + 2;
    vector<long long> divisores;
    for(long long i=1;i<maxP;i++) if ( n % i == 0 ) { divisores.pb( i ); divisores.pb( n/i ); }
    return divisores;
}

int main()
{
    int t;
    long long x, y, ret;
    vector <long long> d;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld %lld", &x, &y);
        if(x+2 == y) printf("%lld\n", x+1);
        else
        {
            d = divisors(x-y+2);
            ret = INF;
            for(int j=0;j<d.size();j++)
            {
                if(d[j] > y-2)
                {
                    ret = min(ret,d[j]);
                }
            }
            if(ret == INF) printf("Impossible\n");
            else printf("%lld\n", ret);
        }
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int m = 1e9+9;

ll exp(ll n, ll e) {
    if(!e) return 1;
    if(e&1) return n*exp(n,e-1)%m;
    return exp(n*n%m,e/2);
}

ll f[111111];

int main()
{
    ll n, i3 = exp(6,m-2);
    f[0] = 1;
    for(int i=1;i<=100001;i++) f[i] = f[i-1]*i%m;
    while(scanf("%lld", &n) && n) {
        n -= 3;
        cout << (f[n]*(((n+3)*(n+2)%m)*(n+1)%m)%m)*i3%m << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll dp[111111];

int main() {
    ll n;
    for(int i=3;i<100;i++) {
        dp[i] += (((i-1)/2) * ((i+1)/2))/2;
    }
    for(int i=1;i<10;i++) cout << dp[i] << endl;
    while(scanf("%lld", &n) != EOF) {
        ll num = dp[n];
        ll den = n*n;
        ll g = __gcd(num,den);
        printf("%lld/%lld\n", num, den);
    }
    return 0;
}


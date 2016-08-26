#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz size()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

const int N = 111111;

int n, o;
int top[N], bot[N], times[N];

int solve(int k) {
    int r = 1000000;
    int b = 0, t=0, d=0;
    for(int j=0;j<n;j++) {
        if(top[j] == bot[j] && top[j] == k) d++;
        else if(top[j] == k) t++;
        else if(bot[j] == k) b++;
    }
    if(t + b + d >= o) r = max(0,o-(t+d));
    return r;
}

int main() {
    int m;
    cin >> n;
    m = 1000000;
    o = (n+1)/2;
    for(int i=0;i<n;i++) {
        cin >> top[i] >> bot[i];
        times[top[i]]++;
        times[bot[i]]++;
    }
    for(int i=0;i<=100001;i++) {
        if(times[i] >= o) {
            m = min(m,solve(i));
        }
    }
    if(m == 1000000) cout << "Impossible" << endl;
    else cout << m << endl;
    return 0;
}

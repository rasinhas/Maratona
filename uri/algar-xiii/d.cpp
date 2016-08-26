#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cassert>
#include <climits>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll p[55];
string a;
int asz;

// resolve do inicio ao fim
string solve(ll n, ll sz) {
    string ret;
    if(!sz) return "";
    ll idx = n/p[sz-1];
    //cout << idx << " " << n << " " << p[sz-1] << endl;
    ret = a[idx];
    ret += solve(n-idx*p[sz-1], sz-1);
    return ret;
}

// resolve do fim para o inicio
string solve2(ll n, ll sz) {
    string ret;
    if(!sz) return "";
    ll next = n/asz;
    ll idx = (n%asz);
    ret = a[idx];
    ret += solve2(next,sz-1);
    return ret;
}

int main()
{
    ll n, t;
    cin >> t;
    while(t--) {
        cin >> a;
        cin >> n;
        asz = (ll)a.size();
        int sz;
        p[0] = 1;
        for(sz=1;sz<50;sz++) {
            if(p[sz-1] > LLONG_MAX/asz) p[sz] = 0;
            else p[sz] = p[sz-1]*asz;
        }
        ll s = 0;
        for(sz=1;sz<50;sz++) {
            if(s > LLONG_MAX - p[sz]) break;
            if(p[sz] == 0) break;
            if(s + p[sz] >= n) break;
            s += p[sz];
        }
        n -= s;
        string ret, ret2;
        ret = solve2(n-1,sz);
        reverse(ret.begin(),ret.end());
        ret2 = solve(n-1,sz);
        assert(ret==ret2);
        cout << ret2 << endl;
    }
    return 0;
}

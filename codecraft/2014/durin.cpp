#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
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

int f[111111];

void fail(string p) {
    int m=p.sz, k=0;
    f[0] = 0;
    f[1] = 0;
    for(int i=1;i<m;i++)
    {
        while(k>0 && p[k] != p[i]) k=f[k-1];
        if(p[k] == p[i]) k++;
        f[i]=k;
    }
}

vector <int> kmp(string t, string p) {
    fail(p);
    vector <int> s;
    int j=0, m=p.sz, n=t.sz;
    for(int i=0;i<n;i++){
        while(j > 0 && p[j] != t[i]) j = f[j-1];
        if(p[j] == t[i]) j++;
        if(j == m) {
            s.push_back(i-m+1);
        }
    }
    return s;
}

vector <int> k;

int main() {
    string a, b;
    cin >> a;
    cin >> b;
    k = kmp(b,a);
    for(int i=0;i<k;i++) {
    }
    return 0;
}

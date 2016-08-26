#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

map <string,int> f;
string names[222222];
int p[111111];
int vis[111111];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> names[2*i] >> names[2*i+1];
        f[names[2*i]] = f[names[2*i+1]] = i+1;
    }
    sort(names,names+2*n);
    for(int i=0;i<n;i++) cin >> p[i];
    int i = 0, v = 0;
    while(1) {
        if(i >= 2*n) break;
        if(v >= n) break;
        if(f[names[i]] == p[v]) v++;
        i++;
    }
    cout << (v == n ? "YES" : "NO") << endl;
    return 0;
}


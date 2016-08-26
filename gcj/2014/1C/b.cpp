#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll m = 1e9+7;
string s[111];
int b[111], a[111];
int adj[33][33], ig[33], og[33], vis[111];
ll f[111], w[111];
int n;

void minisolve(int x) {
    b[x] = a[x] = -1;
    w[x] = 1;
    int c = 0;
    int ok = 1;
    for(int i=0;i<n;i++) {
        int pt = 0;
        int vv = 0;
        while(pt < s[i].size()) {
            while(s[i][pt] == s[i][pt+1]) pt++;
            if(s[i][pt] == 'a'+x) {
                vv++;
                vis[x] = vis[x]+1;
            }
            pt++;
        }
        int k = s[i].size()-1;
        if(vv >= 2) {
            w[x] = 0;
            ok = 0;
        }
        if(vv == 1) {
            if(s[i][0] != 'a'+x) {
                if(b[x] == -1) b[x] = s[i][0];
                else {
                    w[x] = 0;
                    ok = 0;
                }
            }
            if(s[i][k] != 'a'+x) {
                if(a[x] == -1) a[x] = s[i][k];
                else {
                    w[x] = 0;
                    ok = 0;
                }
            }
            if(s[i][0] == 'a'+x && s[i][k] == 'a'+x) c++;
        }
    }
    if(ok) w[x] = f[c];
}

int main() {
    int T;
    cin >> T;
    f[0] = 1;
    for(int i=1;i<=100;i++) f[i] = (f[i-1]*i)%m;
    for(int t=1;t<=T;t++) {
        memset(adj,0,sizeof(adj));
        memset(ig,0,sizeof(ig));
        memset(og,0,sizeof(og));
        memset(w,0,sizeof(w));
        memset(vis,0,sizeof(vis));
        cin >> n;
        for(int i=0;i<n;i++) cin >> s[i];
        for(int i=0;i<26;i++) minisolve(i);
        int c=0;
        for(int i=0;i<26;i++) {
            if(b[i] == -1 && vis[i]) {
                c++;
            }
        }
        ll ans = f[c]; 
        if(c == 0) ans = 0;
        for(int i=0;i<26;i++) {
            ans = (ans*w[i])%m;
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}

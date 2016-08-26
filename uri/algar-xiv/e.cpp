#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int vis[111];

int main() {
    int n, q;
    while(scanf("%d%d", &n, &q) && n) {
        string s;
        cin >> s;
        for(int i=0;i<q;i++) {
            int k, m;
            cin >> k >> m;
            int p = 0;
            int z = 1;
            memset(vis,0,sizeof(vis));
            while(!vis[p]) {
                vis[p] = z++;
                p += k;
                p %= n;
            }
            z--;
            int x = m/z;
            for(int j=0;j<n;j++) {
                if(vis[j]) {
                    int y = (x + (m%z >= vis[j] ? 1 : 0))%2;
                    if(y) {
                        if(s[j] == 'x') printf("o");
                        else printf("x");
                    } else printf("%c", s[j]);
                } else printf("%c", s[j]);
            }
            cout << endl;
        }
    }
    return 0;
}


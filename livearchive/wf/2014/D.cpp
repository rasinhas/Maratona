#include <bits/stdc++.h>
using namespace std;
    
int n;
char s[111];
int ans[111][111];
int can[(1<<25) + 15];

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        int m;
        cin>>m;
        for(int j=0;j<m;j++) {
            scanf("%s", s);
            int mask=0;
            int tam = strlen(s);
            int pos=0;
            for(int k=0;k<n;k++) if(pos < tam && s[pos] == 'a'+k) {
                pos++;
                mask += 1<<k;
            }
            can[mask] |= 1<<i;
        }
    }
    for(int i=0;i<n;i++) can[1<<i] |= 1<<i;
    for(int i=1;i<1<<n;i++) {
        for(int j=0;j<n;j++) if(i & (1<<j)) {
            can[i] |= can[i - (1<<j)];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) ans[j][i]=-1;
        ans[i][i]=0;
        int mask = 1<<i;
        int d=0;
        while(1) {
            int oldmask = mask;
            mask |= can[mask];
            d++;
            int ok=0;
            for(int j=0;j<n;j++) if(((oldmask & (1<<j)) == 0) && (mask & (1<<j))) {
                ok = 1;
                ans[j][i] = d;
            }
            if(!ok) break;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

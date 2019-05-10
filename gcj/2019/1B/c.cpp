#include <bits/stdc++.h>

using namespace std;

int c[11111], d[11111];

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n, k, r = 0;
        cin >> n >> k;
        for(int i=0;i<n;i++) cin >> c[i];
        for(int i=0;i<n;i++) cin >> d[i];
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                int bc = 0, bd = 0;
                for(int l=i;l<=j;l++) {
                    bd = max(bd,d[l]);
                    bc = max(bc,c[l]);
                }
                if(max(bc,bd)-min(bc,bd) <= k) r++;
            }
        }
        printf("Case #%d: %d\n", t, r);
    }
    return 0;
}

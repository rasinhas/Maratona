#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int q[111], p[111];
pii dp[50];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=0;i<n;i++) cin >> q[i] >> p[i];
        for(int i=0;i<=50;i++) dp[i] = pii(-1,-1);
        dp[0] = pii(0,0);
        for(int i=0;i<n;i++) {
            for(int j=50;j>=0;j--) {
                if(dp[j].ff != -1) {
                    if(j + p[i] <= 50) {
                        dp[j+p[i]] = max(dp[j+p[i]],mp(dp[j].ff+q[i],dp[j].ss-1));
                    }
                }
            }
        }
        int mi = 0;
        for(int i=0;i<=50;i++) {
            if(dp[i] > dp[mi]) mi = i;
        }
        printf("%d brinquedos\n", dp[mi].ff);
        printf("Peso: %d kg\n", mi);
        printf("sobra(m) %d pacote(s)\n", n+dp[mi].ss);
        cout << endl;
    }
    return 0;
}


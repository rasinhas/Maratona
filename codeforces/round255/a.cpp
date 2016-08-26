#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int b[333];

int main() {
    int p, n;
    cin >> p >> n;
    int ans = 1e9;
    for(int i=0;i<n;i++) {
        int k;
        cin >> k;
        if(b[k%p]) ans = min(i+1,ans);
        else b[k%p]++;
    }
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}


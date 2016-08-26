#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int r[111111], v[111], p[111];

int main() {
    int t, n, m;
    while(cin >> n && n) {
        memset(r,-1,sizeof(r));
        r[0] = 0;
        for(int i=0;i<n;i++) cin >> v[i] >> p[i];
        cin >> m;
        for(int i=0;i<n;i++) for(int j=m;j>=0;j--) if(r[j] > -1) r[j+p[i]] = max(r[j+p[i]],r[j]+v[i]);
        int k = 0;
        for(int i=m;i>=0;i--) k = max(k,r[i]);
        cout << k << endl;
    }
    return 0;
}


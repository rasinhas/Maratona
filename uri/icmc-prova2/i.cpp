#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int c[111111];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        memset(c,0,sizeof(c));
        for(int i=0;i<m;i++) {
            int a;
            scanf("%d", &a);
            c[a]++;
        }
        int r = -1;
        for(int i=1;i<=n;i++) if(2*c[i] > m) r = i; 
        cout << r << endl;
    }
    return 0;
}


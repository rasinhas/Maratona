#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int c[111111];
set <int> neig[111111];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) scanf("%d", &c[i]);
    int mm = *min_element(c,c+n);
    for(int i=0;i<m;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        if(c[a] != c[b]) {
            neig[c[a]].insert(c[b]);
            neig[c[b]].insert(c[a]);
        }
        if(neig[c[a]].size() > neig[mm].size()) mm = c[a];
        if(neig[c[a]].size() == neig[mm].size() && c[a] < mm) mm = c[a];
        if(neig[c[b]].size() > neig[mm].size()) mm = c[b];
        if(neig[c[b]].size() == neig[mm].size() && c[b] < mm) mm = c[b];
    }
    cout << mm << endl;
    return 0;
}


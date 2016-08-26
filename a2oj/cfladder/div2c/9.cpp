#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int cx = 1, cy = 1;
int n, m, k;
int vis[333][333];

int get_next() {
    vis[cx][cy] = 1;
    if(cx+1 <= n && vis[cx+1][cy] == 0) {
        cx++;
        return 1;
    }
    if(cx-1 > 0 && vis[cx-1][cy] == 0) {
        cx--;
        return 1;
    }
    if(cy+1 <= m && vis[cx][cy+1] == 0) {
        cy++;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> m >> k;
    for(int i=1;i<k;i++) {
        cout << 2;
        for(int j=0;j<2;j++) {
            printf(" %d %d", cx, cy);
            get_next();
        }
        cout << endl;
    }
    cout << n*m - 2*(k-1);
    do {
        printf(" %d %d", cx, cy);
    } while(get_next());
    cout << endl;
    return 0;
}


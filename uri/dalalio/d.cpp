#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int c[5];
int dv[4] = {1,0,0,-1};
int dh[4] = {0,-1,1,0};
string ret[5] = {"DOWN", "LEFT", "RIGHT", "UP", "NONE"};
int a[11][11];

int check(int v, int h, int dir) {
    if(a[v][h] == 0) return 0;
    if(v+dv[dir] < 0 || v+dv[dir] > 3 || h+dh[dir] < 0 || h+dh[dir] > 3) return 0;
    if(a[v+dv[dir]][h+dh[dir]] == 0 || a[v+dv[dir]][h+dh[dir]] == a[v][h]) return 1;
    else return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        for(int i=0;i<4;i++) for(int j=0;j<4;j++) cin >> a[i][j];
        memset(c,0,sizeof(c));
        int win = 0;
        for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(a[i][j] == 2048) win = 1;
        for(int k=0;k<4;k++) for(int i=0;i<4;i++) for(int j=0;j<4;j++) {
            c[k] = max(c[k],check(i,j,k));
        }
        int r = 0;
        for(int i=0;i<4;i++) r += c[i];
        if(r == 0 || win) cout << ret[4] << endl;
        else {
            int f = 0;
            for(int i=0;i<4;i++) {
                if(c[i]) {
                    if(f) cout << " ";
                    cout << ret[i];
                    f++;
                }
            }
            cout << endl;
        }

    }
    return 0;
}


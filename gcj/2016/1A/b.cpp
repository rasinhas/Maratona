#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int l[111][55], l2[111][55];
int g[55][55];
int c[2], miss;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n;
        cin >> n;
        miss = -1;
        memset(l,0,sizeof(l));
        memset(l2,0,sizeof(l2));
        memset(g,0,sizeof(g));
        printf("Case #%d:", t);
        for(int i=0;i<2*n-1;i++) for(int j=0;j<n;j++) {
            cin >> l[i][j];
            l2[i][j] = l[i][j];
        }
        // generate grid and clear l
        for(int i=0;i<n;i++) {
            int m = 2554;
            c[0] = c[1] = -1;
            for(int j=0;j<2*n-1;j++) {
                if(l[j][i] < m) {
                    m = l[j][i];
                    c[0] = j;
                    c[1] = -1;
                }
                else if(l[j][i] == m) c[1] = j;     
            }
            if(c[1] == -1) miss = i;
            for(int j=0;j<i;j++) {
                if(g[i][j] != 0 && l[c[0]][j] != g[i][j]) {
                    swap(c[0],c[1]);
                    for(int k=0;k<i;k++) {
                        if(g[i][k] != 0 && l[c[1]][k] != g[k][i]) {
                            cout << "EREREE" << endl;
                        }
                    }
                    break;
                }
            }
            for(int j=0;j<n;j++) {
                if(c[0] != -1) g[i][j] = l[c[0]][j];
                if(c[1] != -1) g[j][i] = l[c[1]][j];
            }
            for(int j=0;j<n;j++) {
                if(c[0] != -1) l[c[0]][j] = 2555;
                if(c[1] != -1) l[c[1]][j] = 2555;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << g[i][j] << "  ";
            }
            cout << endl;
        }
        //test grid
        int o = 0;
        for(int j=0;j<2*n-1;j++) {
            int v = 1;
            for(int k=0;k<n;k++) {
                if(g[miss][k] != l2[j][k]) {
                    v = 0;
                    break;
                }
            }
            if(v) {
                o = 1;
                break;
            }
        }
        if(!o) for(int j=0;j<n;j++) printf(" %d", g[miss][j]);
        else for(int j=0;j<n;j++) printf(" %d", g[j][miss]);
        cout << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

pii f[333], h;

int main() {
    int s, a, b, n, m, ss, aa, bb;
    cin >> s >> a >> b;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> f[i].ff >> f[i].ss;
    }
    cin >> m;
    int best = -1, bi, bj, r;
    for(int i=0;i<m;i++) {
        int k = 0;
        cin >> r >> h.ff >> h.ss;
        if(h.ff <= s) {
            if(r == 1) k = h.ss + a;
            else k = h.ss + b;
            if(k > best) {
                best = k;
                bi = i;
                bj = -1;
            }
        }
        if(r == 2) {
            for(int j=0;j<n;j++) {
                if(2*s >= h.ff && 2*f[j].ff >= h.ff) {
                    k = h.ss + f[j].ss;
                    if(k > best) {
                        best = k;
                        bi = i;
                        bj = j;
                    }
                }
            }
        }
    }
    if(best == -1) cout << "Forget about apartments. Live in the dormitory." << endl;
    else if(bj == -1) cout << "You should rent the apartment #"<<bi+1<<" alone." << endl;
    else cout << "You should rent the apartment #"<<bi+1<<" with the friend #"<<bj+1<<"." << endl;
    return 0;
}


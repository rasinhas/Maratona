#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[111], r[111], p[111], f[111], v[111];

int main() {
    int n;
    string s = "";
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        a[i]--;
        r[a[i]] = i;
    }
    for(int i=0;i<n;i++) {
        cin >> p[i];
        p[i]--;
    }
    int l = -1;
    int ok = 1;
    for(int i=0;i<n;i++) {
        if(p[i] != -1 && v[p[i]] != 1) {
            if(v[p[i]] == 2) {
                ok = 0;
                break;
            }
            v[p[i]] = 1;
            int k = r[p[i]];
            for(int j=i-1;j>l;j--) {
                p[j] = k;
                if(v[p[j]]) {
                    ok = 0;
                    break;
                }
                k = r[k];
                v[p[j]] = 2;
            }
            l = i;
            while(!v[a[p[l]]]) {
                p[l+1] = a[p[l]];
                l++;
            }
            if(!ok) break;
        }
    }
    for(int i=0;i<n;i++) if(p[i] == -1) ok = 0;
    if(!ok) cout << -1;
    else for(int i=0;i<n;i++) {
        if(i) cout << " ";
        cout << p[i]+1;
    }
    cout << endl;
    return 0;
}


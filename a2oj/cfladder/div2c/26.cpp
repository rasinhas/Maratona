#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int np[11111111], c[11111111], p[11111111];

void sieve(int n) {
    np[1] = 1;
    for(int i=2;i<=n;i+=2) {
        np[i] = 1; 
        p[2] += c[i];
    }
    for(int i=3;i<=n;i+=2) if(np[i] == 0) {
        p[i] = c[i];
        for(int j=i+i;j<=n;j+=i) {
            np[j] = 1;
            p[i] += c[j];
        }
    }
}

int main() {
    int n, k, maxk = 0;
    cin >> n;
    memset(c,0,sizeof(c));
    memset(p,0,sizeof(p));
    for(int i=0;i<n;i++) {
        scanf("%d", &k);
        maxk = max(k,maxk);
        c[k]++;
    }
    sieve(maxk);
    for(int i=1;i<=maxk;i++) p[i] += p[i-1];
    int q;
    cin >> q;
    for(int i=0;i<q;i++) {
        int l, r;
        cin >> l >> r;
        if(r > maxk) r = maxk;
        if(l > maxk) l = maxk+1;
        cout << p[r]-p[l-1] << endl;
    }
    return 0;
}


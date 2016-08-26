#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int pref[11111], suf[11111];
int l2, l3;
ll l, x, n;
// (position,parity)
vector <pii> pl, sl;
// 1 = 1; i = 2; j = 3; k = 4;
int quat[6][6] = {{0,0,0,0,0},
                  {0,1,2,3,4},
                  {0,2,-1,4,-3},
                  {0,3,-4,-1,2},
                  {0,4,3,-2,-1}};

int mod(int a) { return a > 0 ? a : -a; }

int mult(int a, int b) {
    int c = quat[mod(a)][mod(b)];
    if(a*b < 0) c *= -1;
    return c;
}

int conv(char s) {
    if(s == 'i') return 2;
    if(s == 'j') return 3;
    if(s == 'k') return 4;
}

// x*a = b
int inve(int a, int b) {
    for(int i=1;i<=4;i++) {
        if(mult(i,a) == b) return i;
        if(mult(i,a) == -b) return -i;
    }
}

//a*x = b
int invd(int a, int b) {
    for(int i=1;i<=4;i++) {
        if(mult(a,i) == b) return i;
        if(mult(a,i) == -b) return -i;
    }
}

int check(pii p, pii s) {
    int mi = p.ss+s.ss;
    if(mi >= x) return 0;
    // J is in the middle of L
    if(mi+1 == x) {
        // no letter in the middle of p and s
        if(s.ff - p.ff < 2) return 0;
        if(inve(suf[s.ff],suf[p.ff+1]) == conv('j')) return 1;
    } else {
        // j is gonna be a suffix + prefix
        int k1 = suf[p.ff+1], k2 = pref[s.ff-1];
        mi += 2;
        if(p.ff == n-1) k1 = 1;
        if(s.ff == 0) k2 = 1;
        int m = (x-mi)%4;
        if(m == 0 && mult(k1,k2) == conv('j')) return 1; 
        if(m == 1 && mult(k1,mult(suf[0],k2)) == conv('j')) return 1; 
        if(m == 2 && mult(k1,mult(l2,k2)) == conv('j')) return 1; 
        if(m == 3 && mult(k1,mult(l3,k2)) == conv('j')) return 1; 
    }
}

int main() {
    int T;
    string s;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> l >> x;
        cin >> s;
        n = s.size();
        pl.clear();
        sl.clear();
        if(l*x > 2) {
            pref[0] = conv(s[0]);
            for(int i=1;i<n;i++) {
                int k = conv(s[i]);
                pref[i] = mult(pref[i-1],k);
            }
            suf[n-1] = conv(s[n-1]);
            for(int i=n-2;i>=0;i--) {
                int k = conv(s[i]);
                suf[i] = mult(k,suf[i+1]);
            }
            l2 = mult(suf[0],suf[0]);
            l3 = mult(suf[0],l2);
            int n2, n3, n4;
            for(int i=0;i<n;i++) {
                n2 = mult(suf[0],pref[i]), n3 = mult(l2,pref[i]), n4 = mult(l3,pref[i]);
                if(pref[i] == conv('i')) pl.push_back(mp(i,0));
                if(n2 == conv('i')) pl.push_back(mp(i,1));
                if(n3 == conv('i')) pl.push_back(mp(i,2));
                if(n4 == conv('i')) pl.push_back(mp(i,3));
            }
            for(int i=n-1;i>=0;i--) {
                n2 = mult(suf[i],suf[0]), n3 = mult(suf[i],l2), n4 = mult(suf[i],l3);
                if(suf[i] == conv('k')) sl.push_back(mp(i,0));
                if(n2 == conv('k')) sl.push_back(mp(i,1));
                if(n3 == conv('k')) sl.push_back(mp(i,2));
                if(n4 == conv('k')) sl.push_back(mp(i,3));
            }
        }
        int ok = 0;
        for(int i=0;i<pl.size();i++) {
            for(int j=0;j<sl.size();j++) {
                ok = check(pl[i],sl[j]);
                if(ok) break;
            }
            if(ok) break;
        }
        printf("Case #%d: %s\n", t, (ok ? "YES" : "NO"));
    }
    return 0;
}


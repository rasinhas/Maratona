#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int mod(int a) { return a > 0 ? a : -a; }
int ba = 0, bb = 0, bd = 1e8;
string as, bs;
void go(string a, string b, int idx){
    if(idx == a.size()) {
        int ca = 0, cb = 0;
        for(int i=0;i<a.size();i++) {
            ca = ca*10 + a[i]-'0';
            cb = cb*10 + b[i]-'0';
        }
        if(bd > mod(ca-cb)) {
            ba = ca;
            bb = cb;
            as = a;
            bs = b;
            bd = mod(ca-cb);
        }
        else if(bd == mod(ca-cb)) {
            if(ca < ba) {
                ba = ca;
                bb = cb;
                as = a;
                bs = b;
                bd = mod(ca-cb);
            }
            else if(ca == ba) {
                if(cb < bb) {
                    ba = ca;
                    bb = cb;
                    as = a;
                    bs = b;
                    bd = mod(ca-cb);
                }
            }
        }
        return ;
    }
    if(a[idx] == '?') {
        string c = a;
        for(int i=0;i<10;i++) {
            c[idx] = '0'+i;
            go(c,b,idx);
        }
    } else {
        if(b[idx] == '?') {
            string c = b;
            for(int i=0;i<10;i++) {
                c[idx] = '0'+i;
                go(a,c,idx+1);
            }
        }
        else go(a,b,idx+1);
    }
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        printf("Case #%d: ", t);
        string a, b;
        bd = 1e8;
        cin >> a >> b;
        go(a,b,0);
        cout << as << " " << bs << endl;
    }
    return 0;
}


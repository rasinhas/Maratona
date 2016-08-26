#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll mod(ll a) { return a > 0 ? a : -a; }

string ba, bb;
ll bd;

void go(string a, string b, int idx, ll dif) {
    if(idx == a.size()) {
        dif = mod(dif);
        if(dif < bd) {
            ba = a;
            bb = b;
            bd = dif;
        } else if(dif == bd) {
            if(a < ba) {
                ba = a;
                bb = b;
                bd = dif;
            } else if(a == ba) {
                if(b < bb) {
                    ba = a;
                    bb = b;
                    bd = dif;
                }
            }
        }
        return ;
    }
    if(a[idx] != '?' && b[idx] != '?') return go(a,b,idx+1,dif*10+(a[idx]-b[idx]));
    if(a[idx] == '?' && b[idx] == '?') {
        if(dif == 0) {
            a[idx] = '0';
            b[idx] = '0'; 
            go(a,b,idx+1,dif*10+a[idx]-b[idx]);
            b[idx] = '1';
            go(a,b,idx+1,dif*10+a[idx]-b[idx]);
            a[idx] = '1';
            b[idx] = '0'; 
            return go(a,b,idx+1,dif*10+a[idx]-b[idx]);
        } else {
            if(dif > 0) a[idx] = '0', b[idx] = '9';
            else a[idx] = '9', b[idx] = '0';
            return go(a,b,idx+1,dif*10+a[idx]-b[idx]);
        }
    } else if(a[idx] == '?') {
        if(dif == 0) {
            a[idx] = b[idx]-1;
            if(b[idx] > '0') go(a,b,idx+1,dif*10+a[idx]-b[idx]);
            a[idx] = b[idx]+1;
            if(b[idx] < '9') go(a,b,idx+1,dif*10+a[idx]-b[idx]);
            a[idx] = b[idx];
            return go(a,b,idx+1,dif*10+a[idx]-b[idx]);
        } else {
            if(dif > 0) a[idx] = '0';
            else a[idx] = '9';
            return go(a,b,idx+1,dif*10+a[idx]-b[idx]);
        }
    } else if(b[idx] == '?') {
        if(dif == 0) {
            b[idx] = a[idx]-1;
            if(a[idx] > '0') go(a,b,idx+1,dif*10+a[idx]-b[idx]);
            b[idx] = a[idx]+1;
            if(a[idx] < '9') go(a,b,idx+1,dif*10+a[idx]-b[idx]);
            b[idx] = a[idx];
            return go(a,b,idx+1,dif*10+a[idx]-b[idx]);
        } else {
            if(dif > 0) b[idx] = '9';
            else b[idx] = '0';
            return go(a,b,idx+1,dif*10+a[idx]-b[idx]);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        printf("Case #%d: ", t);
        string a, b;
        bd = 1e18;
        cin >> a >> b;
        go(a,b,0,0);
        cout << ba << " " << bb << endl;
    }
    return 0;
}


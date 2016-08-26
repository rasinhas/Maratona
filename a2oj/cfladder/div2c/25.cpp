#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll inf = 1e9+7;
int c[3], p[3], n[3];

int main() {
    string s;
    ll r;
    ll h = 0;
    cin >> s;
    cin >> c[0] >> c[1] >> c[2];
    cin >> p[0] >> p[1] >> p[2];
    cin >> r;
    for(int i=0;i<s.size();i++) {
        if(s[i] == 'B') n[0]++;
        else if(s[i] == 'S') n[1]++;
        else n[2]++;
    }
    int cc = n[0]*p[0] + n[1]*p[1] + n[2]*p[2];
    h = (n[0] ? c[0]/n[0] : inf);
    h = min(h,(n[1] ? c[1]/n[1] : inf));
    h = min(h,(n[2] ? c[2]/n[2] : inf));
    if(!n[0]) c[0] = 0;
    if(!n[1]) c[1] = 0;
    if(!n[2]) c[2] = 0;
    c[0] -= h*n[0];
    c[1] -= h*n[1];
    c[2] -= h*n[2];
    int cost;
    while(c[0] || c[1] || c[2]) {
        cost = 0;
        if(c[0] < n[0]) {
            cost += (n[0]-c[0])*p[0];
            c[0] = n[0];
        }
        if(c[1] < n[1]) {
            cost += (n[1]-c[1])*p[1];
            c[1] = n[1];
        }
        if(c[2] < n[2]) {
            cost += (n[2]-c[2])*p[2];
            c[2] = n[2];
        }
        if(cost <= r) {
            r -= cost;
            c[0] -= n[0];
            c[1] -= n[1];
            c[2] -= n[2];
            h++;
        } else break;
    }
    if((c[0]|c[1]|c[2]) == 0) h += r/cc;
    cout << h << endl;
    return 0;
}


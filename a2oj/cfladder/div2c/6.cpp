#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    ll b[4];
    ll ret = 0;
    cin >> b[0] >> b[1] >> b[2];
    sort(b,b+3);
    ret += b[0];
    ll diff = b[2] - b[1];
    if(diff > 2*b[0]) b[2] -= 2*b[0];
    else {
        ll t = b[1] + b[2] - 2*b[0];
        b[1] = t/2;
        b[2] = t-b[1];
    }
    b[0] = 0;
    diff = b[2] - b[1];
    if(diff <= b[1]) {
        b[1] -= diff;
        b[2] -= 2*diff;
        ret += diff;
    } else {
        ret += b[1];
        b[2] -= 2*b[1];
        b[1] -= b[1];
    }
    if(b[1] > 2) {
        ret += 2*(b[1]/3);
        b[1] %= 3;
        b[2] %= 3;
    }
    if(b[1] == 1 && b[2] > 1) ret++;
    if(b[1] == 2 && b[2] > 3) ret += 2;
    if(b[1] == 2 && b[2] > 0 && b[2] < 4) ret++;
    cout << ret << endl;
    return 0;
}


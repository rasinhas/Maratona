#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string solve(int x, int r, int c) {
    if((r*c)%x != 0) return "RICHARD";
    if(x == 1) return "GABRIEL";
    if(x == 2) return "GABRIEL";
    if(x == 3) return ((r == 1 || c == 1) ? "RICHARD" : "GABRIEL");
    if(x == 4) return ((r <= 2 || c <= 2) ? "RICHARD" : "GABRIEL");
    if(x == 5) return ((r <= 2 || c <= 2) ? "RICHARD" : "GABRIEL");
    if(x == 6) return ((r <= 3 || c <= 3) ? "RICHARD" : "GABRIEL");
    return "RICHARD";
}

int main() {
    int T, x, r, c;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> x >> r >> c;
        printf("Case #%d: ", t);
        cout << solve(x,r,c) << endl;
    }
    return 0;
}


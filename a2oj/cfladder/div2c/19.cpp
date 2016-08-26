#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string s;
vector <int> sol;

int go(int diff, int steps, int last) {
    int ret = 0;
    if(steps == 0) {
        sol.push_back(last);
        return 1;
    }
    for(int i=0;i<10;i++) {
        if(s[i] == '1' && (i+1) > diff && i+1 != last) ret = go(i+1-diff,steps-1,i+1);
        if(ret) break;
    }
    if(ret) sol.push_back(last);
    return ret;
}

int main() {
    int n;
    cin >> s;
    cin >> n;
    int ok = go(0,n,0);
    cout << (ok ? "YES" : "NO") << endl;
    reverse(sol.begin(),sol.end());
    if(ok) {
        for(int i=1;i<sol.size();i++) cout << sol[i] << " ";
        cout << endl;
    }
    return 0;
}


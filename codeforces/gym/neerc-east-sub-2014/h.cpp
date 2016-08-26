#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int diff = 'a'-'A';

int mod(int a) { return a > 0 ? a : -a; }

int r[5555];

int main() {
    int n;
    string s;
    stack <pair<char,int> > q;
    cin >> n;
    cin >> s;
    int g = 1, b = 1;
    for(int i=0;i<2*n;i++) {
        if(q.empty()) {
            if(s[i] >= 'a') q.push(mp(s[i],g));
            else q.push(mp(s[i],b));
        }
        else {
            if(mod(s[i]-q.top().ff) == diff) {
                if(s[i] >= 'a') r[q.top().ss] = g;
                else r[b] = q.top().ss;
                q.pop();
            } else {
                if(s[i] >= 'a') q.push(mp(s[i],g));
                else q.push(mp(s[i],b));
            }
        }
        if(s[i] >= 'a') g++;
        else b++;
    }
    if(!q.empty()) cout << "Impossible" << endl;
    else {
        cout << r[1];
        for(int i=2;i<=n;i++) cout << " " << r[i];
        cout << endl;
    }
    return 0;
}


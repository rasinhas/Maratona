#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int mod(int a) { return a > 0 ? a : -a; }

bool cmp(int a, int b) { 
    return mod(a) > mod(b); 
}

int a[1111];

int main() {
    int n, k;
    while(cin >> n >> k && n) {
        vector <int> ans, pos, neg;
        for(int i=0;i<n;i++) {
            cin >> a[i];
            if(a[i] >= 0) pos.push_back(a[i]);
            else neg.push_back(a[i]);
        }
        sort(pos.begin(),pos.end(),cmp);
        sort(neg.begin(),neg.end(),cmp);
        int pp=0, np=0;
        if(k == n) for(int i=0;i<n;i++) pos.push_back(a[i]);
        else {
            while(k) {
                if(k == 1) break;
                if(neg.size()-np < 2) {
                    ans.push_back(pos[pp]);
                    ans.push_back(pos[pp+1]);
                    pp += 2;
                    k -= 2;
                    continue;
                }
                if(pos.size()-pp < 2) {
                    ans.push_back(neg[np]);
                    ans.push_back(neg[np+1]);
                    np += 2;
                    k -= 2;
                    continue;
                }
                if(pos[pp]*pos[pp+1] > neg[np]*neg[np+1]) {
                    ans.push_back(pos[pp]);
                    ans.push_back(pos[pp+1]);
                    pp += 2;
                    k -= 2;
                    continue;
                }
                if(pos[pp]*pos[pp+1] <= neg[np]*neg[np+1]) {
                    ans.push_back(neg[np]);
                    ans.push_back(neg[np+1]);
                    np += 2;
                    k -= 2;
                    continue;
                }
            }
        }
        if(k == 1) {
            if(pos.size() > pp) ans.push_back(pos[pp]);
            else ans.push_back(neg[np]);
        }
        sort(ans.begin(),ans.end());
        cout << ans[0];
        for(int i=1;i<ans.size();i++) printf(" %d", ans[i]);
        cout << endl;
    }
    return 0;
}


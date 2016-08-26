#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <int> ans;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        ans.clear();
        for(int i=2;i<=16;i++) {
            string s, r;
            int aux = a;
            while(aux > 0) {
                s += '0'+(aux%i);
                aux /= i;
            }
            r = s;
            reverse(r.begin(),r.end());
            if(r == s) ans.push_back(i);
        }
        if(ans.size() == 0) cout << "-1" << endl;
        else {
            cout << ans[0];
            for(int i=1;i<ans.size();i++) cout << " " << ans[i];
            cout << endl;
        }
    }
    return 0;
}


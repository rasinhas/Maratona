#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s, p;
    cin >> n;
    for(int i=0;i<n;i++) {
        int ac = 0;
        cin >> s >> p;
        for(int j=0;j<p.size();j++) {
            if(p[j] == 'a') ac++;
        }
        long long ans = (1ll<<s.size());
        if(ac > 1) cout << "-1" << endl;
        else if(ac == 1 && p.size() > 1) cout << "-1" << endl;
        else if(ac == 1 && p.size() == 1) cout << "1" << endl;
        else cout << ans << endl;
    }
    return 0;
}

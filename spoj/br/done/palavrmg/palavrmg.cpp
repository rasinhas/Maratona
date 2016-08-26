#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        string s, s2;
        cin >> s;
        int ok = 1;
        s2 = s;
        for(int i=0;i<s.size();i++) if(s[i] >= 'a') s[i] = 'A' + (s[i]-'a');
        for(int i=1;i<s.size();i++) {
            if(s[i] <= s[i-1]) ok = 0;
        }
        cout << s2 << ": ";
        if(ok) cout << "O" << endl;
        else cout << "N" << endl;
    }
    return 0;
}

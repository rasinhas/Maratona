#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s;
        int idx = 0;
        idx = (s[0]-'a')*25 + s[1]-'a' + 1;
        if(s[1] > s[0]) idx--;
        cout << idx << endl;
    }
    return 0;
}

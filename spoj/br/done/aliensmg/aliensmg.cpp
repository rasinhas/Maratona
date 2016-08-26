#include <bits/stdc++.h>

using namespace std;

set <string> d;

int main() {
    int n;
    string s;
    while(scanf("%d", &n) && n) {
        d.clear();
        for(int i=0;i<n;i++) {
            cin >> s;
            sort(s.begin(),s.end());
            d.insert(s);
        }
        cout << d.size() << endl;
    }
    return 0;
}

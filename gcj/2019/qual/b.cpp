#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        string s;
        int n;
        printf("Case #%d: ", t);
        cin >> n;
        cin >> s;
        n = n*2 - 2;
        for(int i=0;i<n;i++) {
            if(s[i] == 'S') printf("E");
            else printf("S");
        }
        cout << endl;
    }
    return 0;
}

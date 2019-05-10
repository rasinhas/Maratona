#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        string n, a, b;
        cin >> n;
        bool has_started = 0;
        for(int i=0;i<n.size();i++) {
            if(n[i] != '4') {
                a += n[i];
                if(has_started) b += '0';
            } else {
                a += '2';
                b += '2';
                has_started = true;
            }
        }
        printf("Case #%d: ", t);
        cout << a << " " << b << endl;
    }
    return 0;
}

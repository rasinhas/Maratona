#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

set <int> s;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n;
        s.clear();
        for(int i=0;i<n;i++) {
            cin >> c;
            s.insert(c);
        }
        cout << s.size() << endl;
    }
    return 0;
}


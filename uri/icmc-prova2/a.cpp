#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string sa, sb;
        cin >> sa >> sb;
        int r = 0;
        for(int i=0;i<sa.size();i++) {
            if(sa[i] <= sb[i]) r += sb[i]-sa[i];
            else r += 26 + sb[i] - sa[i];
        }
        cout << r << endl;
    }
    return 0;
}


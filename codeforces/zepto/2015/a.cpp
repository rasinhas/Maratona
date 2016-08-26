#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n, ok;
    string s;
    cin >> n;
    cin >> s;
    for(int i=0;i<n;i++) {
        for(int j=1;(i+4*j)<n;j++) {
            int p = i;
            ok = 1;
            for(int k=0;k<5;k++) {
                if(s[p] == '.') ok = 0;
                p += j;
            }
            if(p-j >= n) cout << "OOO" << endl;
            if(ok) break;
        }
        if(ok) break;
    }
    if(!ok) cout << "no" << endl;
    else cout << "yes" << endl;
    return 0;
}


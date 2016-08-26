#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int f[555555];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, c, m;
        cin >> n >> c >> m;
        for(int i=0;i<m;i++) cin >> f[i];
        sort(f,f+m,greater<int>());
        int l=0, h=c;
        int r = 0;
        while(1) {
            if(h > m) h = m;
            r += 2*(*max_element(f+l,f+h));
            if(h == m) break;
            h += c;
            l += c;
        }
        cout << r << endl;
    }
    return 0;
}


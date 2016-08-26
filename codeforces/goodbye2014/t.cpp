#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[333];

int main() {
    int n, tar;
    cin >> n >> tar;
    for(int i=0;i<n-1;i++) cin >> a[i];
    int i = 0;
    bool f = 0;
    while(i<n-1) {
        if(i == tar-1) {
            f = 1;
            break;
        }
        i += a[i];
    }
    if(f) cout << "y" << endl;
    else cout << "n" << endl;
    return 0;
}


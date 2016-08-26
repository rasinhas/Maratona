#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n, h, r=0, a;
    cin >> n >> h;
    for(int i=0;i<n;i++) {
        cin >> a;
        if(a > h) r++;
        r++;
    }
    cout << r << endl;
    return 0;
}


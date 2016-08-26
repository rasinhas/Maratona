#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[111111];
vector <int> sol;

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a,a+n);
    if(n == 1) cout << -1 << endl;
    else {
        if(n == 2) {
            if(a[0] == a[1]) cout << 1 << endl << a[0] << endl;
            else {
                cout << ((a[1]-a[0])%2 ? 2 : 3) << endl;
                cout << 2*a[0] - a[1] << " ";
                if((a[1]-a[0])%2 == 0) cout << (a[1]+a[0])/2 << " ";
                cout << 2*a[1] - a[0] << endl;
            }
        } else {
            int diff;
            diff = min(a[1]-a[0],a[2]-a[1]);
            int ok = 1;
            for(int i=0;i<n-1;i++) {
                if(!ok) break;
                if(a[i] + diff != a[i+1]) {
                    if(a[i]+2*diff == a[i+1]) sol.push_back(a[i]+diff);
                    else ok = 0;
                }
            }
            if(!ok || sol.size() > 1) cout << 0 << endl;
            else {
                if(sol.size() == 1) cout << 1 << endl << sol[0] << endl;
                else {
                    if(diff == 0) cout << 1 << endl << a[0] << endl;
                    else cout << 2 << endl << a[0] - diff << " " << a[n-1] + diff << endl;
                }
            }
        }
    }
    return 0;
}


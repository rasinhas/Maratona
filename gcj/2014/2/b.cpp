#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[1111];
int n;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        int r = 0, f = 0, l = n;
        for(int i=0;i<n;i++) {
            int mp = min_element(a+f,a+l)-a;
            if(mp - f <= l - mp - 1) {
                for(int i=mp;i>f;i--) {
                    swap(a[i],a[i-1]);
                    r++;
                }
                f++;
            } else {
                for(int i=mp;i<l-1;i++) {
                    swap(a[i],a[i+1]);
                    r++;
                }
                l--;
            }
        }
        printf("Case #%d: %d\n", t, r);
    }
    return 0;
}


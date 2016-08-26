#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int l[111111], r[111111];
int a[111111];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int c = 0;
    for(int i=0;i<n;i++) {
        if(a[i+1] > a[i]) c++;
        else {
            for(int j=0;j<=c;j++) {
                r[i-j] = i;
            }
            c = 0;
        }
    }
    l[0] = 0;
    for(int i=0;i<n;i++) {
        if(r[i] == r[i+1]) {
            l[i+1] = l[i];
        } else {
            l[i+1] = i+1;
        }
    }
    int ans = 0;
    ans = max(r[1]+1,n-l[n-2]);
    for(int i=1;i<n-1;i++) {
       if(a[i-1]+1 < a[i+1]) ans = max(ans,r[i+1]-l[i-1]+1);
       else ans = max(ans,max(i-l[i-1]+1,r[i+1]-i+1));
    }
    cout << ans << endl;
    return 0;
}


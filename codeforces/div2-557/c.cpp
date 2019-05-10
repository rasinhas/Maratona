#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
typedef long long ll;

using namespace std;

int a[111111], first[111111], last[111111];

int main() {
    int n, k;
    int solution = 3*n;
    cin >> n >> k;
    memset(last,-1,sizeof(last));
    memset(first,0,sizeof(first));
    for(int i=0;i<k;i++) {
        cin >> a[i];
        last[a[i]] = i+1;
        if(first[a[i]] == 0) first[a[i]] = i+1;
    }
    int s = 0;
    for(int i=1;i<=n;i++) {
        if(i > 1 && (last[i-1] < first[i] || first[i-1] == 0 || first[i] == 0)) {
            s++;
        }
        if(first[i] == 0) {
            s++;
        }
        if(i < n && (last[i+1] < first[i]  || first[i] == 0 || first[i+1] == 0)) {
            s++;
        }
    }
    cout << s << endl;
    return 0;
}

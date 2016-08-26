#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int q[111], aux[111];

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        string s;
        cin >> s;
        int n = s.size(), r = 0;
        for(int i=0;i<n;i++) q[n-i-1] = s[i] == '+' ?  1 : 0;
        for(int i=0;i<n;i++) {
            if(q[i]) continue;
            if(q[n-1] == 1) {
                int j = n-1;
                while(q[j]) {
                    q[j] = 1-q[j];
                    j--;
                }
                r++;
            }
            for(int j=i;j<n;j++) aux[j] = 1-q[n-j+i-1];
            for(int j=i;j<n;j++) q[j] = aux[j];
            r++;
        }
        printf("Case #%d: %d\n", t, r);
    }
    return 0;
}

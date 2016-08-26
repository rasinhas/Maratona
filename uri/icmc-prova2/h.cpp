#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 333;

int x1[1111], x2[1111], y11[1111], y2[1111];
int d[N];

int mod(int a) { return a > 0 ? a : -a; }

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for(int i=0;i<n;i++) scanf("%d%d", &x1[i], &y11[i]);
        for(int i=0;i<m;i++) scanf("%d%d", &x2[i], &y2[i]);
        int p = 0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
            d[p++] = (mod(x1[i]-x2[j])+mod(y11[i]-y2[j]));
            if(p == N) {
                nth_element(d,d+k,d+N);
                p = k;
            }
        }
        nth_element(d,d+k,d+p);
        int r = 0;
        for(int i=0;i<k;i++) r += d[i];
        cout << r << endl;
    }
    return 0;
}


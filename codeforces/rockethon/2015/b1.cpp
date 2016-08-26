#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int p[55];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1;i<55;i++) p[i-1] = i;
    int mm = 0;
    for(int i=0;i<n;i++) {
        int s2 = 0;
        for(int j=i;j<n;j++) {
            int pp = 1e9;
            for(int k=i;k<=j;k++) pp = min(pp,p[k]);
            s2 += pp;
        }
        mm += s2;
    }
    int ii = 0;
    do {
        int s1 = 0;
        for(int i=0;i<n;i++) {
            int s2 = 0;
            for(int j=i;j<n;j++) {
                int pp = 1e9;
                for(int k=i;k<=j;k++) {
                    pp = min(pp,p[k]);
                }
                s2 += pp;
            }
            s1 += s2;
        }
        if(s1 == mm) ii++;
        if(ii == m) break;
    } while(next_permutation(p,p+n));
    cout << p[0];
    for(int i=1;i<n;i++) cout << " " << p[i];
    cout << endl;
    return 0;
}

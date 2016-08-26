#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n, m;
    cin >> n >> m;
    double r = 0;
    for(int i=1;i<=min(m,n);i++) {
        double p = 1;
        for(int j=0;j<n;j++) {
            if(j < i) {
                p *= (1.0*(m-j)/(m*n-j));
            }
            else {
                p *= (1.0*(m*n-j-m+i)/(m*n-j));
            }
        }
        cout << p << endl;
        r += (p*i);
    }
    printf("%.12lf\n", r);
    return 0;
}


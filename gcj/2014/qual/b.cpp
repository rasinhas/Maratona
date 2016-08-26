#include <bits/stdc++.h>

using namespace std;

const int N=111111;
double dp[N];

int main() {
    int T, m;
    double c, f, x;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> c >> f >> x;
        double best = 1e9;
        int idx = -1;
        dp[0] = 0;
        double cr = 2.0;
        for(int i=0;i<N;i++) {
            if(i) dp[i] = dp[i-1] + c/cr;
            if(i) cr += f;
            best = min(best, dp[i] + x/cr);
        }
        printf("Case #%d: %.7lf\n", t, best);
    }
    return 0;
}

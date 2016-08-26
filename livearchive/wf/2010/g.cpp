#include <bits/stdc++.h>

using namespace std;

double dp[111][111], d[111][111];
double x[111], y[111];
int n;
// por definição b1 no primeiro e b2 no segundo

double dist(int a, int b) {
    return hypot(x[a]-x[b],y[a]-y[b]);
}

void backtrack() {
    vector <int> l, r;
    int lp = n-1, rp = n-1;
    reverse(l.begin(),l.end());
    for(int i=0;i<l.size();i++) printf("%d ", l[i]);
    printf("%d", n-1);
    for(int i=0;i<r.size();i++) printf(" %d", r[i]);
    cout << "TODO" << endl;
}

int main() {
    int b1, b2, t=1;
    while(scanf("%d%d%d", &n, &b1, &b2) && n) { 
        for(int i=0;i<n;i++) cin >> x[i] >> y[i];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
            dp[i][j] = 1e9;
            d[i][j] = dist(i,j);
        }
        if(b2 == 1) swap(b1,b2);
        dp[0][0] = 0;
        double best = 1e9;
        // para cada vertice q posso escolher
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                // i vai pro primeiro caminho (b2 vai sempre pelo segundo)
                if(i != b2) {
                    // o i-1 foi pelo segundo caminho -> verifico quem é o melhor pra ficar antes de mim (i)
                    dp[i][i-1] = min(dp[i][i-1], dp[j][i-1]+d[i][j]);
                    // o i-1 foi pelo primeiro caminho -> verifico quem é o melhor pra ser o ultimo no segundo caminho
                    dp[i][j] = min(dp[i][j], dp[i-1][j]+d[i-1][i]);
                }
                // i vai pro segundo caminho (b1 vai sempre pelo primeiro)
                if(i != b1 && i != 1) {
                    // o i-1 foi pelo primeiro caminho -> verifico quem é o melhor pra ficar antes de mim (i)
                    dp[i-1][i] = min(dp[i-1][i], dp[i-1][j]+d[i][j]);
                    // o i-1 foi pelo segundo caminho -> verifico quem é o melhor pra ser o ultimo no primeiro caminho
                    dp[j][i] = min(dp[j][i], dp[j][i-1]+d[i-1][i]);
                }
            }
        }
        for(int i=0;i<n-1;i++) dp[n-1][n-1] = min(dp[n-1][n-1], min(dp[n-1][i] + d[i][n-1], dp[i][n-1] + d[i][n-1]));
        printf("Case %d: %.2lf\n", t++, dp[n-1][n-1]);
        backtrack();
    }
    return 0;
}

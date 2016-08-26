#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int l[11], r[11];
double p[11];

int main() {
    int n;
    cin >> n;
    int mi=10001, ma=0;
    for(int i=0;i<n;i++) {
        cin >> l[i] >> r[i];
        p[i] = 1.0/(r[i]-l[i]+1.0);
        mi = min(mi,l[i]);
        ma = max(ma,r[i]);
    }
    double exp = 0.0;
    // suponho que i é a segunda maior oferta
    for(int i=mi;i<=ma;i++) {
        // pi = p[j]==i & pmi = p[j]<i
        double pi[11], pmi[11];
        for(int j=0;j<n;j++) {
            pi[j] = pmi[j] = 0;
            if(l[j] <= i && r[j] >= i) pi[j] = p[j];
            else pi[j] = 0;
            if(r[j] < i) pmi[j] = 1.0;
            else if (l[j] <= i) pmi[j] = p[j]*(i-l[j]);
            else pmi[j] = 0.0;
        }
        double pp, prob = 0.0;
        // supondo que j foi o vencedor o(j) >= i
        for(int j=0;j<n;j++) {
            //venceu com o(j) > i
            if(l[j] > i) pp = p[j]*(r[j]-l[j]+1);
            else if(l[i] == i) pp = p[j]*(r[j]-l[j]);
            else {
                if(r[j] <= i) pp = 0.0;
                else pp = p[j]*(r[j]-i);
            }
            // o que acontece com os outros
            // alguem tem que fazer oferta de i e o resto < i
            for(int k=1;k<(1<<n);k++) {
                double ppk = 1.0;
                for(int x=0;x<n;x++) {
                    // é igual a i
                    if(k&(1<<x)) {
                        ppk *= pi[x];
                    } else {
                        if(x != j) ppk *= pmi[x];
                        else ppk *= pp;
                    }
                }
                if(__builtin_popcount(k) == 1 && ((1<<j)&k)) ppk = 0.0;
                else {
                    if((1<<j)&k) ppk /= __builtin_popcount(k);
                }
                prob += ppk;
            }
        }
        exp += prob*i;
    }
    printf("%.12lf\n", exp);
    return 0;
}


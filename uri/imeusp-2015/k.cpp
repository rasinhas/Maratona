#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

double s[4444];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=0;i<n;i++) cin >> s[i];
        double best = 1e9;
        sort(s,s+n);
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
            double a = s[i], b = s[j];
            int k = lower_bound(s,s+n,b-a)-s;
            while(k < n && (k == i || k == j)) k++;
            if(k >= n) continue;
            if(s[k] > a+b) continue;
            double c = s[k];
            double p = (a+b+c)/2.0;
            best = min(best,sqrt(p*(p-a)*(p-b)*(p-c)));
        }
        if(best == 1e9) cout << -1 << endl;
        else printf("%.2lf\n", best);
    }
    return 0;
}


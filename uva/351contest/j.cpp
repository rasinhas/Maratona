#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int v[555];

int main() {
    int j, r;
    while(scanf("%d%d", &j, &r) != EOF) {
        memset(v,0,sizeof(v));
        for(int i=0;i<r*j;i++) {
            int c;
            scanf("%d", &c);
            v[i%j] += c;
        }
        int best = j-1;
        for(int i=j-2;i>=0;i--) if(v[i] > v[best]) best = i;
        cout << best+1 << endl;
    }
    return 0;
}


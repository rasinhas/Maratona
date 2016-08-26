#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int v[111111];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int s, r, c;
        double ret=0;
        scanf("%d%d%d", &s, &c, &r);
        for(int i=0;i<s;i++) scanf("%d", &v[i]);
        sort(v,v+s);
        for(int i=0;i<s;i++) {
            if(i < c) ret += (1.0/(v[i]+r));
            else ret += (1.00/v[i]);
        }
        printf("%.2lf\n", ret);
    }
    return 0;
}


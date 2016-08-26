#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

pii l[3333];

int main() {
    int n, x, y;
    while(scanf("%d", &n) != EOF) {
        for(int i=0;i<n;i++) {
            scanf("%d%d", &x, &y);
            l[i] = make_pair(x,y);
        }
        sort(l,l+n);
        int r = 0;
        for(int i=0;i<n;i++) {
            int maxy = 1e8, miny = -1e8;
            for(int j=i+1;j<n;j++) {
                if(l[j].ss < l[i].ss) {
                    if(l[j].ss > miny) {
                        r++;
                        miny = l[j].ss;
                    }
                }
                if(l[j].ss > l[i].ss ){
                    if(l[j].ss < maxy) {
                        r++;
                        maxy = l[j].ss;
                    }
                }
                if(l[j].ss == l[i].ss) miny = maxy = l[j].ss;
            }
        }
        cout << r << endl;
    }
    return 0;
}


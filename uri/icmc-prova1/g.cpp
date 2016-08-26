#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[1111111];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k, s;
        scanf("%d%d%d", &n, &k, &s);
        a[0] = s;
        for(int i=1;i<n;i++) a[i] = (1LL*a[i-1]*1103515245 + 12345) % (2147483648LL);
        priority_queue <pair<int,int> > q;
        for(int i=0;i<k;i++) q.push(mp(a[i],i));
        ll r = q.top().ff;
        for(int i=k;i<n;i++) {
            q.push(mp(a[i],i));
            while(1) {
                int f = q.top().ff;
                int id = q.top().ss;
                if(id > i-k) {
                    r += f;
                    break;
                }
                q.pop();
            }
        }
        printf("%lld\n", r);
    }
    return 0;
}


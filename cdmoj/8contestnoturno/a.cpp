#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[11111111];
priority_queue<int> q;

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        ll s = 0;
        for(int i=0;i<n;i++) {
            scanf("%d", &a[i]);
            s += a[i];
        }
        sort(a,a+n,greater<int>());
        int d = 2, p = 1;
        while(!q.empty()) q.pop();
        q.push(-a[0]-1);
        int ok = 1;
        int sz = 1;
        if(s < n-1) ok = 0;
        while(1) {
            int pf = p+sz;
            if(pf >= n) break;
            for(int i=p;i<pf;i++) {
                q.push(-d-a[i]);
                sz++;
            }
            while(!q.empty() && q.top() == -d) {
                q.pop();
                sz--;
            }
            if(q.empty()) ok = 0;
            if(!ok) break;
            p = pf;
            d++;
        }
        if(!ok) d = -1;
        printf("%d\n", d);
    }
    return 0;
}


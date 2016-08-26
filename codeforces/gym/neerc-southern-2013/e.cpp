#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int N = 555555, M=1000001;
int n;

vector<pii> v[N];
int h[N], val[N], vis[N];
int t[M];

int query(int x) {
    int ret=0;
    for(;x;x-=x&-x) ret += t[x];
    return ret;
}

long long sum=0;

void add(int x, int v) { for(;x<M;x+=x&-x) t[x]+=v; }

void insert(int x, int h) { for(int oldx=x;x<N;x+=x&-x) v[x].push_back(pii(h, n - oldx + 1)); }

void remove(int x, int h) {
    for(;x;x-=x&-x) {
        int p = lower_bound(v[x].begin(), v[x].end(), pii(h, N+1), greater<pii>()) - v[x].begin();
        for(int i=p;i<v[x].size();i++) {
            int y = v[x][i].first;
            int pos = v[x][i].second;
            if(vis[pos]) continue;
            vis[pos]=1;
            sum -= val[pos];
        }
        v[x].resize(p);
    }
}


int main() {
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=n;i>=1;i--) {
        val[i] = query(h[i]-1);
        sum+=val[i];
        add(h[i], 1);
    }
    for(int i=1;i<=n;i++) insert(n-i+1, h[i]);
    for(int i=1;i<=n;i++) sort(v[i].begin(), v[i].end(), greater<pii>());
    cout << sum << endl;
    for(int i=0;i<m;i++) {
        int pos;
        cin>>pos;
        remove(n-pos+1, h[pos]);
        cout << sum << endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N=1e4;
vector<pii> x, y;

ll hash[N], sum[N], v[N];

int main() {
    int n, w;
    x.resize(N);
    y.resize(N);
    srand(time(NULL));
    while(cin>>n>>w && n) {
        for(int i=0;i<n;i++) {
            scanf("%d%d", &x[i].first, &y[i].first);
            x[i].second = y[i].second = i;
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        set <ll> s;
        s.insert(0);
        for(int i=0;i<n;i++) hash[i] = ((1ll+rand())%1234567) * ((1ll+rand())%1234567);
        for(int t=0;t<2;t++) {
            vector<int> vx;
            for(int i=0;i<n;i++) vx.push_back(x[i].first);
            vx.erase(unique(vx.begin(), vx.end()), vx.end());
            for(int i=0;i<vx.size();i++) {
                v[i] = sum[i] = 0;
            }
            int j=0;
            for(int i=0;i<vx.size();i++) {
                while(j!=n && x[j].first == vx[i]) v[i]+=hash[x[j++].second];
            }
            for(int i=1;i<vx.size();i++) sum[i] = sum[i-1] + v[i-1];
            for(int i=0;i<vx.size();i++) {
                s.insert(v[i]);
                for(int j=i+1;j<vx.size();j++) if(vx[j] - vx[i] <= w){
                    s.insert(sum[j] - sum[i] + v[j]);
                    s.insert(sum[j] - sum[i]);
                    s.insert(sum[j] - sum[i] - v[i] + v[j]);
                    s.insert(sum[j] - sum[i] - v[i]);
                }
            }
            x=y;
        }
        cout << s.size()-1 << endl;
    }
    return 0;
}

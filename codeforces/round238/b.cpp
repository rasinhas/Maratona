#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define ff first
#define ss second

using namespace std;

typedef long long ll;

const int M = 1001001;

int x[M], vis[M];
vector<int> y;
int s = (int)1e6;

int main() {
    int m;
    cin >> m;
    ll sum = 0;
    for(int i=0;i<m;i++) {
        scanf("%d", &x[i]);
        vis[x[i]] = 1;
        sum += (x[i]-1);
    }
    int p = 0;
    for(int i=0;i<m;i++) {
        if(!vis[s-x[i]+1]) y.push_back(s-x[i]+1);
        else {
            p++;
        }
    }
    p /= 2;
    for(int i=1;i<=s;i++) {
        if(!p) break;
        if(!vis[i] && !vis[s-i+1]) {
            y.push_back(i);
            y.push_back(s-i+1);
            p--;
        }
    }
    cout << y.size() << endl;
    for(int i=0;i<y.size();i++) printf("%d ", y[i]);
    cout << endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
typedef long long ll;

const int N=111, M=10001;
const ll INF=(ll)1e17;
ll v[N];
ll dp[2][M], c[N];

int main() {
    int n, k;
    cin>>n>>k; 
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v, v+n);
    int y, x=0, p=0;
    for(y=0;y<n;y++) if(v[y+1] >= k || y == n-1) break;
    while(x < y)
    {
        if(v[x] + v[y] <= k)
        {
            v[y] += v[x];
            v[x++] = INF;
            p++;
        }
        else y--;
    }
    sort(v, v+n);
    n -= p;
    for(int i=1;i<M;i++) dp[0][i]=INF;
    c[0] = INF;
    if(v[0] <= k) dp[0][v[0]] = c[0] = 1;
    for(int i=1;i<n;i++) {
        if(v[i] <= k) c[i]=1;
        else {
            c[i]=INF;
            for(int j=k;j>=0;j--) c[i] = min(c[i], dp[(i+1)%2][v[i]-j]+1);
        }
        for(int j=M-1;j>=0;j--) {
            if(j<v[i]) dp[i%2][j]=dp[(i+1)%2][j];
            else dp[i%2][j] = min(dp[(i+1)%2][j], dp[(i+1)%2][j-v[i]] + c[i]);
        }
    }
    int t=0;
    ll sum=0;
    for(int i=0;i<n && c[i] != INF;i++) {
        sum += v[i];
        t += c[i];
    }
    cout << sum << " " << t << endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int vis[1001000];
int dif[1001000];

int mod(int a) { return a > 0 ? a : -a; }

int main()
{
    int n, k, m;
    int maxv=0;
    int a[6000];
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        maxv = max(maxv,a[i]);
    }
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) dif[mod(a[i]-a[j])]++;
    for(m=n-k;m<1000002;m++)
    {
        int kl = k;
        if(dif[m] > k) continue;
        for(int i=0;i<n;i++)
        {
            if(vis[a[i]%m] == m) kl--;
            vis[a[i]%m] = m;
        }
        if(kl >= 0) break;
    }
    cout << m << endl;
    return 0;
}

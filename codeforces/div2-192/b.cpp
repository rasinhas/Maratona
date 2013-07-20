#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int vis[1111];

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        vis[a] = vis[b] = 1;
    }
    int i;
    for(i=1;i<=n;i++) if(!vis[i]) break;
    cout << n-1 << endl;
    for(int j=1;j<=n;j++)
    {
        if(j != i) cout << i << " " << j << endl;
    }
    return 0;
}

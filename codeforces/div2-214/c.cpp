#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int a[100], b[100];
// sa - ksb, sa
map <int,int> m[111];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    m[0][0] = 0;
    int best = -1;
    map <int,int>::iterator it;
    for(int i=0;i<n;i++)
    {
        int d = a[i]-k*b[i];
        m[i+1] = m[i];
        for(it=m[i].begin();it!=m[i].end();it++)
        {
            int na = it->first + d;
            m[i+1][na] = max(m[i+1][na],a[i]+it->second); 
        }
    }
    if(m[n][0] == 0) cout << -1 << endl;
    else cout << m[n][0] << endl;
    return 0;
}

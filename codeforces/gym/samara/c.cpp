#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
typedef long long ll;

int a[222222];
map <ll,ll> m;

int main()
{
    int n;
    ll s, ac=0, ans=0;
    cin >> n >> s;
    m[0]++;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        ac += a[i];
        ll v = ac-s;
        if(m.count(v)) ans += m[v];
        m[ac]++;
    }
    cout << ans << endl;
    return 0;
}

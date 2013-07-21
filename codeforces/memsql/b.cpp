#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

set <ll> sol;
set <ll>::iterator it;

int main()
{
    ll n, p;
    cin >> n;
    p = 1;
    for(int i=0;i<63;i++)
    {
        ll l=1;
        ll h=min(2000000000ll, p==1?2000000000ll:(n/(p-1)+1));
        ll m;
        ll f;
        while(l <= h)
        {
            m = (h+l)/2;
            f = (m*(m-1ll))/2+m*(p-1ll);
            if(f == n)
            {
                if(m%2) sol.insert(m*p);
                break;
            }
            if(f >= n) h=m-1;
            else l=m+1;
        }
        p *= 2;
    }
    if(sol.empty()) cout << -1 << endl;
    else for(it=sol.begin();it!=sol.end();it++) cout << *it << endl;
    return 0;
}

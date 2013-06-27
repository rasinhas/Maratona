#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#define inf 0x3f3f3f3f;
#define pb push_back
#define sz size()
#define mp make_pair

typedef long long ll;

using namespace std;

int main()
{
    ll x, y, m, ret;
    cin >> x >> y >> m;
    if(x < y) swap(x,y);
    if((x <= 0 && y <= 0) && m > x) cout << -1 << endl;
    else if(x >= m) cout << 0 << endl;
    else
    {
        ret = 0;
        if(y < 0)
        {
            ret = (-y+(x-1))/x;
            y = (y+x*ret)%x;
        }
        for(;x<m;ret++)
        {
            y = x + y;
            if(x < y) swap(x,y);
        }
        cout << ret << endl;
    }
    return 0;
}

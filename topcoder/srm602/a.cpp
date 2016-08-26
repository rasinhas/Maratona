#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#define ff first
#define ss second

using namespace std;

typedef long long ll;

class TypoCoderDiv1{
    public:
    int getmax(vector <int> d, int x)
    {
        // (ptos, (posição, max até agora))
        int m;
        pair<ll,pair<int,int> > ini = make_pair(x,make_pair(0,0));
        queue <pair<ll,pair<int,int> > > q;
        q.push(ini);
        while(!q.empty())
        {
            pair<ll,pair<int,int> > u = q.front();
            q.pop();
            ll na = u.ff + d[u.ss.ff];
            ll nd = max(0ll,u.ff - d[u.ss.ff]);
            m = max(m,u.ss.ss);
            //printf("( %lld, ( %d, %d ) )\n", u.ff, u.ss.ff, u.ss.ss);
            if(u.ss.ff < d.size())
            {
                if(u.ff + d[u.ss.ff] >= 2200)
                {
                    if(u.ss.ff < d.size()-1)
                    {
                        ll k = u.ff + d[u.ss.ff] - d[u.ss.ff+1];
                        if(k < 2200) q.push(make_pair(k,make_pair(u.ss.ff+2,u.ss.ss+2)));
                    }
                    else q.push(make_pair(na,make_pair(u.ss.ff+1,u.ss.ss+1)));
                }
                else q.push(make_pair(na,make_pair(u.ss.ff+1,u.ss.ss)));
                q.push(make_pair(nd,make_pair(u.ss.ff+1,u.ss.ss)));
            }
        }
        return m;
    }
};

int main()
{
    TypoCoderDiv1 a;
    int k[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};
    vector <int> v(k,k+sizeof(k)/sizeof(int));
    cout << a.getmax(v,1328) << endl;
    return 0;
}

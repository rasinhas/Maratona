#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

ll hh[22222];
ll c = 1000000007;

ll exp(ll a, ll e) 
{
    if(!e) return 1;
    if(e%2) return a*exp(a, e-1);
    return exp(a*a, e/2);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, s, p;
        ll h=0, r=0;
        cin >> n >> m;
        memset(hh,0,sizeof(hh));
        for(int i=1;i<=n;i++)
        {
            cin >> s;
            hh[i] = hh[i-1] + exp(c,s);
        }
        for(int i=0;i<m;i++)
        {
            cin >> p;
            h += exp(c, p);
        }
        for(int i=1;i<=(n-m+1);i++) if(hh[m+i-1]-hh[i-1] == h) r += i*i;
        cout << r << endl;
    }
    return 0;
}

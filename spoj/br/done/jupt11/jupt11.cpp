#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll t[111111];
ll pow[111111];
ll inv[111111];
ll b, p, l, n;

ll fexp(ll i, ll e) {
    if(e == 0) return 1;
    if(e == 1) return i;
    if(e%2 == 0) return fexp((i*i)%p,e/2);
    else return (i*fexp(i,e-1))%p;
}

void init() {for(int i=0;i<111111;i++) t[i] = 0;}

ll query(int i)
{
    ll ret=0;
    while(i>0)
    {
        ret = (ret + t[i])%p;
        i -= (-i&i);
    }
    return ret;
}

int q2(int i, int j) {return (query(j)+p-query(i))%p;}

void update(int i, ll v)
{
    ll x = (p - q2(i-1,i))%p;
    ll v2 = (v*pow[l-i])%p;
    while(i<=l)
    {
        t[i] = (t[i] + x)%p;
        t[i] = (t[i] + v2)%p;
        i += (-i&i);
    }
}

int main()
{
    while((cin >> b >> p >> l >> n) && n)
    {
        init();
        pow[0] = inv[0] = 1;
        for(int i=1;i<l;i++) pow[i] = (pow[i-1]*b)%p;
        b = fexp(b,p-2);
        for(int i=1;i<l;i++) inv[i] = (inv[i-1]*b)%p;
        for(int i=0;i<n;i++)
        {
            char c;
            int x, y;
            cin >> c >> x >> y;
            if(c == 'E')
            {
                update(x,y);
            }
            else
            {
                cout << (q2(x-1,y)*inv[l-y])%p << endl;
            }
        }
        cout << "-" << endl;
    }
    return 0;
}

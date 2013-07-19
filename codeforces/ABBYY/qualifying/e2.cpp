#include <stdio.h>
#include <iostream>
#define MOD 1000000000
#define ll long long

using namespace std;

// t[0] = f[n+1]; t[1] = f[n]
ll tree[2][200200];
ll a[200200];
ll f[200200];
int n;

ll mod(ll a) { return (a%MOD+MOD)%MOD; }

int read(int idx, int t)
{
    ll sum=0;
    while(idx > 0)
    {
        sum = mod(sum+tree[t][idx]);
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, ll val, int t)
{
    while(idx<=n)
    {
        tree[t][idx] = mod(tree[t][idx]+val);
        idx+=(idx & -idx);
    }
}

void init()
{
    for(int i=1;i<=n;i++)
    {
        update(i,mod(a[i]*f[i-1]),0);
        update(i,mod(a[i]*f[i]),1);
    }
}

int main()
{
    int m;
    ll t, x, r, l, v, ret;
    cin >> n >> m;
    f[0] = f[1] = 1;
    f[-1] = 0;
    for(int i=2;i<200100;i++) f[i] = mod(f[i-1]+f[i-2]);
    for(int i=1;i<=n;i++) cin >> a[i];
    init();
    while(m--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> x >> v;
            update(x,mod(mod(v-a[x])*f[x-1]),0);
            update(x,mod(mod(v-a[x])*f[x]),1);
            a[x] = v;
        }
        else if(t == 2)
        {
            cin >> l >> r;
            ll t1 = read(r,1)-read(l-1,1);
            ll t2 = read(r,0)-read(l-1,0);
            if(l%2) ret = mod(mod(f[l-1]*t2)-mod(f[l-2]*t1));
            else ret = mod(mod(f[l-2]*t1)-mod(f[l-1]*t2));
            cout << ret << endl;
        }
    }
    return 0;
}


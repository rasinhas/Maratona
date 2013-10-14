#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b) { return b ? gcd(b,a%b) : a; }

ull lcm(ull a, ull b) { return (a/gcd(a,b))*b; }

int main()
{
    int n, f=0, ctz=-1, ef=0;
    ull m[1111], l=1;
    cin >> n;
    for(int i=0;i<n;i++) 
    {
        cin >> m[i];
        if(!(m[i]%2))
        {
            ef++;
            if(ctz == -1) ctz = 63-__builtin_ctzll(m[i]);
            if(ctz-(63-__builtin_ctzll(m[i])) != 0) f = 1;
        }
        if(m[i] >= (1ull<<32)) f = 1;
    }
    if(f) cout << 0 << endl; 
    else {
        sort(m,m+n);
        ull l=1;
        for(int i=n-1;i>=0;i--)
        {
            l = lcm(l,m[i]);
            if(l < m[i]) f = 1;
        }
        ull a = m[n-1] + (m[n-1]*(m[n-1]-1))/2;
        if(f) cout << 0 << endl;
        else if(ef == 0)
        {
            ull b = (a%l ? (l-a%l) : 0);
            cout << a + b << endl;
        }
        else
        {
            ull r = l/2;
            ull b = (a%l > r ? (l-(a%l-r)) : (r-a%l));
            cout << a + b << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

typedef unsigned long long ll;

char c[55];

int main()
{
    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        ll n, sz, p, k=0;
        string s;
        cin >> s >> n;
        sz = s.size();
        p = 1;
        while(p <= n)
        {
            if(p == 0) break;
            n -= p;
            p *= sz;
            k++;
        }
        for(int i=k-1;i>=0;i--)
        {
            c[i] = s[n%sz];
            n /= sz;
        }
        printf("Case #%d: %s\n", t, c);
    }
    return 0;
}

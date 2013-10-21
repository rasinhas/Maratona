#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll a[1111111];

ll mod(ll a) { return a > 0 ? a : -a; }

int main()
{
    int n;
    ll w;
    while(scanf("%d", &w) != EOF)
    {
        cin >> n;
        w *= 10000000;
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        int d = -1;
        for(int i=0;i<n;i++)
        {
            if(binary_search(a,a+n,w-a[i]))
            {
                if(a[i]*2 == w)
                {
                    if((a[i-1] == a[i] || a[i+1] == a[i]) && d == -1) d = 0;
                }
                else if(mod(2*a[i]-w) > d) d = mod(2*a[i]-w);
            }
        }
        if(d == -1) cout << "danger" << endl;
        else printf("yes %lld %lld\n", (w-d)/2, (w+d)/2);
    }
    return 0;
}

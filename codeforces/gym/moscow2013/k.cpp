#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

const int M=2000000;
int v[M], m;
ll x[3];

int main()
{
    int n, k, a, b, c;
    ll p;
    while(cin >> n >> k && !cin.eof())
    {
        int idx = 0;
        cin >> x[0] >> x[1] >> a >> b >> c;
        for(int i=1;i<=n;i++)
        {
            p = (x[1-i&1]*a + x[i&1]*b + c)%(1u<<31);
            x[1-i&1] = p;
            v[idx++] = -p;
            if(idx == M || i == n)
            {
                nth_element(v,v+k,v+idx);
                idx = k;
            }
        }
        sort(v,v+k);
        printf("%d", -v[0]);
        for(int i=1;i<k;i++) printf(" %d", -v[i]);
        cout << endl;
    }
    return 0;
}

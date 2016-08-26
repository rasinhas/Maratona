#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int p[1111];

int main()
{
    int n, k, l, r, sa, sk;
    cin >> n >> k >> l >> r >> sa >> sk;
    int sn = sa - sk;
    int mn=0;
    if(n == k) mn = 0;
    else mn = sn/(n-k);
    int mk = sk/k;
    sk -= mk*k;
    sn -= mn*(n-k);
    for(int i=0;i<k;i++) p[i] = mk;
    for(int i=k;i<n;i++) p[i] = mn;
    int i=0;
    while(sk > 0)
    {
        int v = min(sk,r-p[i]);
        p[i] += v;
        sk -= v;
        i++;
    }
    i = k;
    while(sn > 0)
    {
        int v = min(sn,mk-p[i]);
        p[i] += v;
        sn -= v;
        i++;
    }
    cout << p[0];
    for(int i=1;i<n;i++) cout << " " << p[i];
    cout << endl;
    return 0;
}

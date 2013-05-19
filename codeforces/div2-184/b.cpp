#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int f;
    long long p, q, n, a[100], aux;
    cin >> p >> q;
    cin >> n;
    f = 0;
    a[n] = 1000;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++)
    {
        if(q == 0)
        {
            f = 1;
            break;
        }
        if(p/q == a[i] || p/q == a[i]+1)
        {
            aux = p - a[i]*q;
            p = q;
            q = aux;
        }
        else f = 1;
    }
    if(!f && !q) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n, m, k, x, y;
    long long a[100100], l[100100], r[100100], d[100100];
    long long v;
    long long vo[100100], va[100100];
    scanf("%d%d%d", &n, &m, &k);
    memset(va,0,n*sizeof(long long));
    memset(vo,0,m*sizeof(long long));
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> l[i] >> r[i] >> d[i];
    for(int i=0;i<k;i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        vo[x]++;
        vo[y]--;
    }
    v = 0;
    for(int i=0;i<m;i++)
    {
        v += vo[i];
        l[i]--;
        va[l[i]] += d[i]*v;
        va[r[i]] -= d[i]*v;
    }
    v = 0;
    for(int i=0;i<n;i++)
    {
        v += va[i];
        a[i] += v;
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

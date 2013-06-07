#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

long long a[100001];
long long s[100001];

int main()
{
    long long cur;
    int n, m, t, v, x;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    cur = 0;
    for(int i=0;i<m;i++)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> v >> x;
            a[v-1] = x;
            s[v-1] = -cur;
        }
        else if(t == 2)
        {
            cin >> v;
            cur += v;
        }
        else if(t == 3)
        {
            cin >> v;
            cout << a[v-1]+cur+s[v-1] << endl;
        }
    }
    return 0;
}

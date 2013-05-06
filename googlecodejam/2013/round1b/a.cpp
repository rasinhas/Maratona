#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    long long t, a, n, ret, f=0, v;
    long long m[120];
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> a >> n;
        for(int j=0;j<n;j++) cin >> m[j];
        sort(m,m+n);
        f = 0;
        ret = 0;
        if(a == 1) ret = n;
        else 
        {
            for(int j=0;j<n;j++)
            {
                v = 0;
                while(a <= m[j])
                {
                    a += (a-1);
                    v += 1;
                    if(v >= (n-j))
                    {
                        v = (n-j);
                        f = 1;
                        break;
                    }
                }
                ret += v;
                if(f) break;
                a += m[j];
            }
            ret = min(ret,n);
        }
        cout << "Case #" << i+1 << ": " << ret << endl;
    }
    return 0;
}

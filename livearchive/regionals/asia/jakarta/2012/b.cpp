#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int m[111111], s[111111];

int main()
{
    int T, n, a, b, c;
    cin >> T;
    for(int t=0;t<T;t++)
    {
        cin >> n;
        int ans = 0;
        memset(m,0,sizeof(m));
        memset(s,0,sizeof(s));
        for(int i=1;i<n;i++)
        {
            cin >> a >> b >> c;
            a--; b--;
            m[a] = max(m[a],c);
            m[b] = max(m[b],c);
            s[a] += c;
            s[b] += c;
        }
        for(int i=0;i<n;i++)
        {
            if(2*m[i] > s[i]) ans += (2*m[i]-s[i]);
            else if(s[i]&1) ans++;
        }
        cout << "Case #" << t+1 << ": " << ans/2 << endl;
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map <int,int> last;
int s[1111111];
int r[1111111];

int main()
{
    int m, q;
    while((cin >> m >> q) && m)
    {
        last.clear();
        for(int i=0;i<m;i++) r[i] = 0;
        for(int i=0;i<m;i++) 
        {
            cin >> s[i];
            if(last.count(s[i]) > 0) r[i] = last[s[i]];
            last[s[i]] = i;
        }
        int l = m-1;
        for(int i=1;i<m;i++) r[i] = max(r[i],r[i-1]);
        for(int i=m-1;i>=0;i--)
        {
            l = min(r[i],l);
            r[i] = l;
        }
        for(int i=0;i<m;i++)
        {
            cout << r[i] << endl;
        }
        for(int i=0;i<q;i++) cin >> l >> l;
    }
    return 0;
}

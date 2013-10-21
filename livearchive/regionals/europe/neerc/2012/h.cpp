#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

typedef long long ll;

map <ll,int> m;

int main()
{
    string s;
    int n;
    while(scanf("%d", &n) != EOF)
    {
        cin >> s;
        ll cur = 0;
        ll ret = 0;
        m.clear();
        for(int i=0;i<n;i++)
        {
            if(s[i] >= 'a') cur ^= (1ll<<(s[i]-'a'));
            else cur ^= (1ll<<(s[i]-'A'+26));
            if(__builtin_popcountll(cur) < 2) ret++;
            if(m.count(cur)) ret += m[cur];
            for(int j=0;j<52;j++) if(m.count(cur^(1ll<<j))) ret += m[cur^(1ll<<j)];
            m[cur]++;
        }
        cout << ret << endl;
    }
    return 0;
}

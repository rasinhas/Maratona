#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

long long v[1111];

int main()
{
    int T, r;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        string s;
        cin >> s;
        r = 0;
        v[0] = 0;
        for(int i=0;i<s.size();i++)
        {
            v[i+1] = v[i]^(1<<(s[i]-'a'));
        }
        for(int i=0;i<=s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(__builtin_popcount(v[i]^v[j]) < 2) r++;
            }
        }
        printf("Case %d: %d\n", t, r);
    }
    return 0;
}

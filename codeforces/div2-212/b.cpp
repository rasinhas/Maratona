#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int s[3333];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++) cin >> s[i];
    sort(s,s+m);
    int f = 0;
    if(s[0] == 1 || s[m-1] == n) f = 1;
    for(int i=0;i<m-2;i++)
    {
        if(s[i]+1 == s[i+1] && s[i]+2 == s[i+2]) f = 1;
    }
    if(f) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}

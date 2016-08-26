#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    long long l=0, r=0, sz = s.size(), k;
    for(int i=0;i<sz;i++)
    {
        if(s[i] == '^')
        {
            k = i;
            break;
        }
    }
    for(int i=k-1;i>=0;i--) if(s[i] != '=') l += (s[i]-'0')*(k-i);
    for(int i=k+1;i<sz;i++) if(s[i] != '=') r += (s[i]-'0')*(i-k);
    if(l == r) cout << "balance" << endl;
    else cout << (l>r ? "left" : "right") << endl;
    return 0;
}

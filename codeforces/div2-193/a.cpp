#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int p = n;
    int ret = 0;
    while(p < s.size())
    {
        if(s[p-1] == s[p-2] && s[p-2] == s[p-3]) ret++;
        p += n;
    }
    cout << ret << endl;
    return 0;
}

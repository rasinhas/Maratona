#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n, k, c;
    string s;
    cin >> n >> k;
    cin >> s;
    c = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '.') c = 0;
        else c++;
        if(c == k) break;
    }
    if(c == k) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}

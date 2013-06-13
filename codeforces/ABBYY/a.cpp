#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int u[100];

int main()
{
    int c10 = 0;
    int used = 0;
    long long ret = 1;
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '?')
        {
            if(i == 0) ret *= 9;
            else c10++;
        }
        else if(s[i] <= '9' && s[i] >= '0') continue;
        else
        {
            if(u[s[i]-'A']) continue;
            else
            {
                if(i == 0) ret *= 9;
                else ret *= (10-used);
                u[s[i]-'A'] = 1;
                used++;
            }
        }
    }
    cout << ret;
    for(int i=0;i<c10;i++) cout << 0;
    cout << endl;
    return 0;
}

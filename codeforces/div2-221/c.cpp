#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int c[4];

int main()
{
    string s;
    cin >> s;
    int zc = 0, v = -1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '0') 
        {
            zc++;
            continue;
        }
        if(s[i] == '1' && c[0] == 0)
        {
            c[0] = 1;
            continue;
        }
        if(s[i] == '6' && c[1] == 0)
        {
            c[1] = 1;
            continue;
        }
        if(s[i] == '8' && c[2] == 0)
        {
            c[2] = 1;
            continue;
        }
        if(s[i] == '9' && c[3] == 0)
        {
            c[3] = 1;
            continue;
        }
        if(v == -1) v = s[i]-'0';
        else v = (3*v + (s[i]-'0'))%7;
        cout << s[i];
    }
    if(v == 0 || v == -1) cout << "1869";
    if(v == 1) cout << "6198";
    if(v == 2) cout << "1896";
    if(v == 3) cout << "1689";
    if(v == 4) cout << "1986";
    if(v == 5) cout << "1968";
    if(v == 6) cout << "1698";
    for(int i=0;i<zc;i++) cout << '0';
    cout << endl;
    return 0;
}

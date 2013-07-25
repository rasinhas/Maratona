#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int ok;

string move(string s, char c, int i)
{
    if(i < 0) 
    {
        ok = 0;
        return s;
    }
    if(c == 'L') {
        if(s[i] == '4') 
        {
            s[i] = '3';
            s = move(s,c,i-1);
        }
        else if(s[i] == '3') s[i] = '4';
        else if(s[i] == '1')
        {
            s[i] = '2';
            s = move(s,c,i-1);
        }
        else s[i] = '1';
    }
    else if(c == 'R') {
        if(s[i] == '3') 
        {
            s[i] = '4';
            s = move(s,c,i-1);
        }
        else if(s[i] == '4') s[i] = '3';
        else if(s[i] == '2')
        {
            s[i] = '1';
            s = move(s,c,i-1);
        }
        else s[i] = '2';
    }
    else if(c == 'U') {
        if(s[i] == '1') 
        {
            s[i] = '4';
            s = move(s,c,i-1);
        }
        else if(s[i] == '4') s[i] = '1';
        else if(s[i] == '2')
        {
            s[i] = '3';
            s = move(s,c,i-1);
        }
        else s[i] = '2';
    }
    else {
        if(s[i] == '3') 
        {
            s[i] = '2';
            s = move(s,c,i-1);
        }
        else if(s[i] == '2') s[i] = '3';
        else if(s[i] == '4')
        {
            s[i] = '1';
            s = move(s,c,i-1);
        }
        else s[i] = '4';
    }
    return s;
}

int main()
{
    string s, m;
    while(1)
    {
        cin >> s;
        if(s == "END") break;
        cin >> m;
        ok = 1;
        for(int i=0;i<m.size();i++) 
        {
            s = move(s,m[i],(s.size()-1));
            if(!ok) break;
        }
        if(ok) cout << s << endl;
        else cout << "OUT" << endl;
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

string msg;
int var[26];
int v;

int validate(string s)
{
    stack <int> p;
    reverse(s.begin(),s.end());
    msg = "insufficient operands";
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == 'C' || s[i] == 'K' || s[i] == 'A' || s[i] == 'D' || s[i] == 'E' || s[i] == 'J')
        {
            if(!p.empty()) p.pop();
            if(p.empty()) return 0;
        }
        else if(s[i] == 'N')
        {
            if(!p.empty()) continue;
            else return 0;
        }
        else if(s[i] >= 'a' && s[i] <= 'z') 
        {
            if(var[s[i]-'a'] == -1) var[s[i]-'a'] = v++;
            p.push(s[i]);
        }
        else 
        {
            msg = "invalid character";
            return 0;
        }
    }
    if(p.size() > 1) 
    {
        msg = "extraneous text";
        return 0;
    }
    return 1;
}

int val(char c) { return (1<<var[c-'a']); }

int eval(string l)
{
    int ret = 0;
    stack <int> s;
    reverse(l.begin(),l.end());
    for(int i=0;i<(1<<v);i++)
    {
        for(int j=0;j<l.size();j++)
        {
            if(l[j] >= 'a' && l[j] <= 'z') 
            {
                s.push((i&val(l[j]))>0);
            }
            else if(l[j] == 'N')
            {
                int p = s.top();
                s.pop();
                s.push(!p);
            }
            else
            {
                int p = s.top();
                s.pop();
                char q = s.top();
                s.pop();
                if(l[j] == 'C') s.push((!p)|q); 
                else if(l[j] == 'K') s.push(p&q);
                else if(l[j] == 'A') s.push(p|q);
                else if(l[j] == 'D') s.push(!(p&q));
                else if(l[j] == 'E') s.push(!(p^q));
                else s.push(p^q);
            }
        }
        ret += s.top();
        s.pop();
    }
    return ret;
}

int main()
{
    stack <char> p;
    string s;
    while((cin >> s) && s != "")
    {
        v = 0;
        cout << s << " is ";
        memset(var,-1,sizeof(var));
        if(validate(s))
        {
            cout << "valid: ";
            int e = eval(s);
            if(e == 0) cout << "contradiction" << endl;
            else if(e == (1<<v)) cout << "tautology" << endl;
            else cout << "contingent" << endl;
        }
        else  cout << "invalid: " << msg << endl;
        while(!p.empty()) p.pop();
    }
    return 0;
}

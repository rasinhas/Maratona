#include <iostream>
#include <cstdio>
#include <climits>
#include <cassert>

using namespace std;

int g[1111111][27];
int estados;
long long ans;

void init() 
{
    for(int j=0;j<26;j++) g[0][j] = -1;
    g[0][26] = 0;
    estados = 1;
}

void add(string s) 
{
    int e = 0;
    for(int i=0;i<s.size();i++)
    {
        int next = s[i]-'a';
        if (g[e][next] == -1) {
            g[e][next] = estados;
            for(int j=0;j<26;j++) g[estados][j] = -1;
            g[estados][26] = 0;
            estados++;
        }
        e = g[e][next];
    }
    ans += (g[e][26]++);
}

string transform(string s)
{
    int u=0;
    int t[26];
    for(int i=0;i<26;i++) t[i] = -1;
    for(int i=0;i<s.size();i++)
    {
        if(t[s[i]-'a'] == -1) t[s[i]-'a'] = (u++);
        s[i] = ('a'+t[s[i]-'a']);
    }
    return s;
}

int main()
{
    int n;
    string a;
    char s[1111111];
    ans = 0;
    init();
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        add(transform(a));
    }
    cout << ans << endl;
    return 0;
}

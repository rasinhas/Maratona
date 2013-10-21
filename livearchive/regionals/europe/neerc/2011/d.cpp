#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct Trie {
    int g[444444][27];
    int estados;
    void init()
    {
        for(int i=0;i<27;i++) g[0][i] = -1;
        estados = 1;
    }
    void add(string s)
    {
        int e = 0;
        for(int i=0;i<s.size();i++)
        {
            int next = s[i]-'a';
            if(g[e][next] == -1)
            {
                g[e][next] = estados;
                for(int j=0;j<27;j++) g[estados][j] = -1;
                estados++;
            }
            e = g[e][next];
        }
        g[e][26] = 1;
    }
};

Trie pref, suf;
int sufc[26];

void sufcnt(int e)
{
    for(int i=0;i<26;i++)
    {
        if(suf.g[e][i] != -1)
        {
            if(e) sufc[i]++;
            sufcnt(suf.g[e][i]);
        }
    }
}

long long dfs(int e)
{
    long long ret = 0;
    for(int i=0;i<26;i++)
    {
        if(pref.g[e][i] != -1)
        {
            if(e) ret += sufc[i];
            ret += dfs(pref.g[e][i]);
        }
    }
    return ret;
}

int vis[33];

int main()
{
    int n;
    string s;
    long long ans;
    while(scanf("%d", &n) != EOF)
    {
        pref.init();
        suf.init();
        memset(sufc,0,sizeof(sufc));
        memset(vis,0,sizeof(vis));
        int fw=0;
        for(int i=0;i<n;i++)
        {
            cin >> s;
            pref.add(s);
            reverse(s.begin(),s.end());
            suf.add(s);
            if(s.size() == 1)
            {
                if(!vis[s[0]-'a']) fw++;
                vis[s[0]-'a'] = 1;
            }
        }
        sufcnt(0);
        ans = (long long)(pref.estados-1)*(suf.estados-1);
        ans -= dfs(0);
        cout << ans+fw << endl;
    }
    return 0;
}

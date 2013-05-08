#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

struct Trie {
    int g[100100][26];
    int estados;
    Trie() { init(); } 
    void init() 
    {
        for(int j=0;j<26;j++) g[0][j] = -1;
        estados = 1;
    }
    void add(string s) 
    {
        int e = 0;
        int i = 0;
        int next = s[i]-'a';
        while(s[i] != '\0')
        {
            next = (s[i] - 'a');
            if (g[e][next] == -1) {
                g[e][next] = estados;
                for(int j=0;j<26;j++) g[estados][j] = -1;
                estados++;
            }
            e = g[e][next];
            i++;
        }
    }
};

Trie port, esp;
int suf[26];

void sufcnt(int e)
{
    for(int i=0;i<26;i++)
    {
        if(esp.g[e][i] != -1)
        {
            if(e) suf[i]++;
            sufcnt(esp.g[e][i]);
        }
    }
}

long long dfs(int e)
{
    long long ret = 0;
    for(int i=0;i<26;i++)
    {
        if(port.g[e][i] != -1)
        {
            if(e) ret += suf[i];
            ret += dfs(port.g[e][i]);
        }
    }
    return ret;
}

int main()
{
    int i, j, n, p, e;
    long long ans;
    string str;
    while(scanf("%d %d", &p, &e) && p)
    {
        port.init();
        esp.init();
        memset(suf,0,26*sizeof(int));
        for(i=0;i<p;i++)
        {
            cin >> str;
            port.add(str);
        }
        for(i=0;i<e;i++)
        {
            cin >> str;
            reverse(str.begin(),str.end());
            esp.add(str);
        }
        sufcnt(0);
        ans = (long long)(port.estados-1)*(esp.estados-1);
        ans -= dfs(0);
        printf("%lld\n", ans);
    }
    return 0;
}

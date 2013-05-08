#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

// Aho-Corasick com uma estrutura bem intuitiva de Trie

// trie com quantidade insana de memória
// 26 => ended strings // 27 => fail state // 28 => sequence size
int g[1010000][29];
int estados, n;
int ret;
string str[10010];

bool comp(string a, string b) { return a.size() < b.size(); }

void init() 
{
    for(int j=0;j<29;j++) g[0][j] = 0;
    estados = 1;
}

void add(string s) 
{
    int e = 0;
    int i = 0;
    int sum = 0;
    int next = s[i]-'a';
    while(s[i] != '\0')
    {
        next = (s[i] - 'a');
        if (g[e][next] == 0) 
        {
            g[e][next] = estados;
            for(int j=0;j<29;j++) g[estados][j] = 0;
            estados++;
        }
        e = g[e][next];
        i++;
    }
    g[e][26]++;
    g[e][28] = max(g[e][28], sum+1);
}

void ahocorasick()
{
    int r, u, w, aux, i;
    queue <int> q;
    for(i=0;i<26;i++) if(g[0][i]) q.push(g[0][i]);
    while(!q.empty())
    {
        r = q.front();
        q.pop();
        for(i=0;i<26;i++) if(g[r][i])
        {
            u = g[r][i];
            q.push(g[r][i]);
            w = g[r][27];
            while((aux = g[w][i]) == 0 && w!=0) w = g[w][27];
            g[u][27] = aux;
            g[u][28] = max(g[u][28],g[r][28]+g[u][26]);
            g[u][28] = max(g[u][28],g[g[u][27]][28]+g[u][26]);
            ret = max(ret,g[u][28]);
        }
    }
}

//not used
//procura as palavras que dão match
/*
void match(string src, int id)
{
    int i;
    int e=0;
    int p;
    for(i=0;i<=src.size();i++)
    {
        p = e;
        while(1)
        {
            if(g[p][26] && g[p][26]-1 != id)  //match;
            if(!g[p][27]) break;
            p = g[p][27];
        }
        e = g[e][src[i]-'a'];
    }
}
*/

int main()
{
    int i;
    while(scanf("%d", &n) && n)
    {
        init();
        for(i=0;i<n;i++)
        {
            cin >> str[i];
        }
        sort(str,str+n,comp);
        for(i=0;i<n;i++) add(str[i]);
        ret = 1;
        ahocorasick();
        printf("%d\n", ret);
    }
    return 0;
}

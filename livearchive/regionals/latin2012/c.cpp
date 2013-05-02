#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

int g[1000000][27];
int c;
int estados;
void init() 
{
    for(int j=0;j<27;j++) g[0][j] = -1;
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
            for(int j=0;j<27;j++) g[estados][j] = -1;
            estados++;
        }
        e = g[e][next];
        i++;
    }
    g[e][26]++;
}

void go(string src)
{
    int i, j;
    int e=0;
    int p;
    for(i=0;i<src.size();i++)
    {
        p = 0;
        if(i == 0) c++;
        else
        {
            for(j=0;j<27;j++)
            {
                if(g[e][j] != -1) p++;
            }
            if(p > 1) c++;
        }
        e = g[e][src[i]-'a'];
    }
}

int main()
{
    int n, i, j;
    string s[101000];
    while(scanf("%d", &n) != EOF)
    {
        init();
        c = 0;
        for(i=0;i<n;i++)
        {
            cin >> s[i];
            add(s[i]); 
        }
        for(i=0;i<n;i++) go(s[i]);
        printf("%.2lf\n", (double)c/n);
    }
}

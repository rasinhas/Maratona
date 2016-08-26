#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define ff first
#define ss second

using namespace std;

string dic[1001];

int g[470000][29];
int c;
int estados;

void init()
{
    for(int j=0;j<30;j++) g[0][j] = -1;
    g[0][26] = g[0][27] = 0;
    estados = 1;
}

void prep(int e) 
{
    if(g[e][26]) g[e][27] = g[e][26];
    for(int i=0;i<26;i++) {
        if(g[e][i] > -1) {
            prep(g[e][i]);
            g[e][27] += g[g[e][i]][27];
        }
    }
}

void add(string s, int idx)
{
    int e = 0;
    int i = 0;
    int next;
    while(s[i] != '\0')
    {
        next = (s[i] - 'a');
        if (g[e][next] == -1) {
            g[e][next] = estados;
            for(int j=0;j<30;j++) g[estados][j] = -1;
            g[estados][26] = g[estados][27] = 0;
            estados++;
        }
        e = g[e][next];
        i++;
    }
    g[e][26]++;
    g[e][28] = idx;
}

int solve(int e, int k)
{
    if(g[e][27] < k) return -1;
    if(k == 1 && g[e][26] > 0) return g[e][28];
    for(int i=0;i<26;i++) {
        if(g[e][i] > -1) {
            if(g[g[e][i]][27] >= k){
                e = g[e][i];
                break;
            }
            k -= g[g[e][i]][27];
        }
    }
    return solve(e,k);
}

int find(int k, string s)
{
    int e = 0;
    int i = 0;
    int next;
    while(s[i] != '\0')
    {
        next = (s[i] - 'a');
        if(g[e][next] == -1) return -1;
        e = g[e][next];
        i++;
    }
    return solve(e,k);
}

int main()
{
    ifstream in("auto.in");
    ofstream out("auto.out");
    int w, n, k;
    string s;
    in >> w >> n;
    init();
    for(int i=0;i<w;i++) {
        in >> dic[i];
        add(dic[i], i+1);
    }
    prep(0);
    for(int i=0;i<n;i++) {
        in >> k >> s;
        out << find(k,s) << endl;
    }
    return 0;
}

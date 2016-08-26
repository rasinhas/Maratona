#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int n, k, a;
vector <string> dic[33];
vector <string> adj[111];
int sz[33], ac[33], cow[111];
ofstream out("nocow.out");

void find(int p, int idx)
{
    if(idx == a) return;
    if(idx > 0) out << " ";
    out << dic[idx][p/ac[idx]];
    p = p%ac[idx];
    find(p, idx+1);
}

int main()
{
    string s;
    ifstream in("nocow.in");
    in >> n >> k;
    k--;
    in.get();
    for(int i=0;i<n;i++) 
    {
        int f = 0;
        a = 0;
        while(in >> s && s != "cow.")
        {
            if(f)
            {
                adj[i].push_back(s); 
                dic[a++].push_back(s);
            }
            if(s == "no") f = 1;
        }
    }
    for(int i=a-1;i>=0;i--)
    {
        sort(dic[i].begin(),dic[i].end());
        dic[i].erase(unique(dic[i].begin(),dic[i].end()),dic[i].end());
        sz[i] = dic[i].size();
        if(i < a-1) ac[i] = ac[i+1]*sz[i+1];
        else ac[i] = 1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            for(int k=0;k<dic[j].size();k++)
            {
                if(adj[i][j] == dic[j][k])
                {
                    cow[i] += ac[j]*k;
                    break;
                }
            }
        }
    }
    sort(cow,cow+n);
    for(int i=0;i<n;i++)
    {
        if(cow[i] <= k) k++;
        else break;
    }
    find(k,0);
    out << endl;
    return 0;
}

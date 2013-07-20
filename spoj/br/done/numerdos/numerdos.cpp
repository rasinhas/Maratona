#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#define pb push_back
#define sz size()
#define mp make_pair

using namespace std;

map <pair<string,string>, int> id;
map <pair<string,string>, int>::iterator it;

int d[111][111];

int main()
{
    int t=1;
    int m;
    while((cin >> m) && m)
    {
        int c=0;
        for(int i=0;i<111;i++) for(int j=0;j<111;j++) d[i][j] = 1000000000;
        for(int i=0;i<m;i++)
        {
            vector <int> adj;
            while(1)
            {
                string sn, n;
                cin >> sn >> n;
                char last = *(n.end()-1);
                n.erase(n.end()-1);
                pair<string,string> cn(n,sn);
                if(!id.count(cn)) id[cn] = c++;
                adj.pb(id[cn]);
                if(last == '.') break;
            }
            for(int j=0;j<adj.sz;j++) for(int k=j+1;k<adj.sz;k++) d[adj[j]][adj[k]] = d[adj[k]][adj[j]] = 1;
        }
        for(int k=0;k<c;k++) for(int i=0;i<c;i++) for(int j=0;j<c;j++) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        int b;
        if(id.count(mp("Erdos", "P."))) b = id[mp("Erdos", "P.")];
        else b = c;
        cout << "Teste " << t++ << endl;
        for(it=id.begin();it!=id.end();it++)
        {
            int kd = d[it->second][b];
            if(it->second != b)
            {
                cout << it->first.second << " " << it->first.first << ": ";
                if(kd == 1000000000) cout << "infinito" << endl;
                else cout << d[it->second][b] << endl;
            }
        }
        id.clear();
        cout << endl;
    }
    return 0;
}

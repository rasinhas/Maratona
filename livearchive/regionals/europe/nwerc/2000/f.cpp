#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#define pb push_back
#define sz size()
#define mp make_pair

using namespace std;

map <pair<string,string>, int> id;
map <pair<string,string>, int>::iterator it;

vector <int> adj[1111];
int d[1111];

void bfs(int u)
{
    queue <pair<int,int> > q;
    q.push(mp(u,1));
    while(!q.empty())
    {
        u = q.front().first;
        int dd = q.front().second;
        q.pop();
        for(int i=0;i<adj[u].sz;i++)
        {
            int v=adj[u][i];
            if(d[v] == 1e9)
            {
                q.push(mp(v,dd+1));
                d[v] = dd+1;
            }
        }
    }
}

int main()
{
    int t=1;
    int tc;
    int m;
    cin >> tc;
    while(tc--)
    {
        string sn, n;
        int q;
        int c=0;
        cin >> m >> q;
        for(int i=0;i<1111;i++) d[i] = 1e9;
        for(int i=0;i<1111;i++) adj[i].clear();
        for(int i=0;i<m;i++)
        {
            vector <int> pap;
            while(1)
            {
                cin >> sn >> n;
                char last = *(n.end()-1);
                n.erase(n.end()-1);
                pair<string,string> cn(sn,n);
                if(!id.count(cn)) id[cn] = c++;
                pap.pb(id[cn]);
                if(last == ':') break;
            }
            char c[1111];
            scanf("%[^\n]", c);
            getchar();
            for(int j=0;j<pap.sz;j++) for(int k=j+1;k<pap.sz;k++) 
            {
                adj[pap[j]].pb(pap[k]);
                adj[pap[k]].pb(pap[j]);
            }
        }
        int b;
        if(id.count(mp("Erdos,", "P."))) b = id[mp("Erdos,", "P.")];
        else b = c;
        bfs(b);
        cout << "Scenario " << t++ << endl;
        while(q--)
        {
            cin >> sn >> n;
            int dist = d[id[mp(sn,n)]]-1;
            if(dist != 1e9-1) cout << sn << " " << n << " " << dist << endl;
            else cout << sn << " " << n << " " << "infinity" << endl;
        }
        id.clear();
    }
    return 0;
}


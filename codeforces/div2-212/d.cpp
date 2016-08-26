#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int cc;
vector <pair<int,int> > adj[111111];
int vis[111111], r[111111], o[1111111];
long long len[111111];
long long cost = 0;

void dfs(int u)
{
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++)
    {
        len[cc] += adj[u][i].second;
        int v = adj[u][i].first;
        if(!vis[v])
        {
            o[cc] = v;
            dfs(v);
        }
    }
}

int main()
{
    int n, m, p, q;
    cc = 0;
    cin >> n >> m >> p >> q;
    for(int i=0;i<m;i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].push_back(make_pair(b,l));
        adj[b].push_back(make_pair(a,l));
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            r[cc] = i;
            len[cc++] /= 2;
        }
    }
    priority_queue <pair<long long,int> >  pq;
    vector <pair<int,int> > v;
    for(int i=0;i<cc;i++) pq.push(make_pair(-len[i],i));
    while(q < pq.size())
    {
        if(p == 0) break;
        pair <long long,int> x, y, z;
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();
        r[cc] = r[x.second];
        o[cc] = r[y.second];
        if(1 - x.first - y.first > 1000000000) z.first = x.first + y.first - 1000000000;
        else z.first = 2*(x.first+y.first)-1;
        z.second = cc++;
        pq.push(z);
        v.push_back(make_pair(r[x.second],r[y.second]));
        p--;
    }
    if(pq.size() != q) cout << "NO" << endl;
    else
    {
        if(p)
        {
            pair <int,int> x;
            while(!pq.empty() && o[pq.top().second] == 0) pq.pop();
            if(!pq.empty())
            {
                x = pq.top(); pq.pop();
                while(p)
                {
                    v.push_back(make_pair(r[x.second],o[x.second]));
                    p--;
                }
            }
        }
        if(p) cout << "NO" << endl;
        else 
        {
            cout << "YES" << endl;
            for(int i=0;i<v.size();i++) cout << v[i].first << " " << v[i].second << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <int> adj[111111];
int p[111111];
pii stree[111111];
int vis[1111111];
int nod = 1;
int n;

typedef struct
{
    bool k;
    ll u[33];
    ll z[33];
	ll pending;
} interval;

interval M[1111111];

void get_children_values(int node)
{
    for(int i=0;i<32;i++) {
        M[node].u[i] = M[2*node].u[i] + M[2*node+1].u[i];
        M[node].z[i] = M[2*node].z[i] + M[2*node+1].z[i];
    }
}

void fix_pending(int node, int b, int e)
{
	if(!M[node].pending) return;
    for(int i=0;i<32;i++) if((1<<(31-i))&M[node].pending) swap(M[node].u[i], M[node].z[i]);
	if(b != e)
	{
		M[2*node].pending = (M[2*node].pending ^ M[node].pending);
		M[2*node+1].pending = (M[2*node+1].pending ^ M[node].pending);
	}
	M[node].pending = 0;
}

interval join(interval i1, interval i2)
{
	interval aux;
    for(int i=0;i<32;i++) {
        aux.u[i] = i1.u[i] + i2.u[i];
        aux.z[i] = i1.z[i] + i2.z[i];
    }
	return aux;
}

interval query(int node, int b, int e, int i, int j)
{
	interval p1, p2;
	fix_pending(node, b, e);
	if(j<b || i>e)
	{
        memset(p1.u,0,sizeof(p1.u));
        memset(p1.z,0,sizeof(p1.z));
        p1.k = -1;
		return p1;
	}
	if(i<=b && j>=e) return M[node];
	else
	{
		p1=query(2*node, b, (b+e)/2, i, j);
		p2=query(2*node+1, (b+e)/2+1, e, i, j);
		if(p1.k==-1) return p2;
		if(p2.k==-1) return p1;
		return join(p1, p2);
	}
}

void update(int node, int b, int e, int i, int j, ll v)
{
	if(i<=b && j>=e)
	{
		M[node].pending = (M[node].pending ^ v);
		fix_pending(node, b, e);
		return;
	}
	if(j<b || i>e) fix_pending(node, b, e);
	else
	{
        fix_pending(node,b,e);
		update(2*node, b, (b+e)/2, i, j, v);
		update(2*node+1, (b+e)/2+1, e, i, j, v);
		get_children_values(node);
	}
}

interval initialize(int node, int b, int e)
{
	M[node].pending = 0;
    M[node].k = 1;
    for(int i=0;i<32;i++) {
        M[node].u[i] = 0;
        M[node].z[i] = 1;
    }
	if(b != e)
	{
		initialize(2*node, b, (b+e)/2);
		initialize(2*node+1, (b+e)/2+1, e);
		get_children_values(node);
	}
}

ll sum(interval a) {
    ll s = 0;
    for(int i=0;i<32;i++) s += a.u[i]*(1<<(31-i));
    return s;
}

void dfs(int u) {
    vis[u] = 1;
    int f = 0;
    for(int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if(!vis[v]) {
            dfs(v);
            if(!f) stree[u].ff = stree[v].ff;
            if(f == adj[u].size()-2) stree[u].ss = stree[v].ss + 1;
            f++;
        }
    }
    if(u == 1) stree[u].ss = stree[adj[u][adj[u].size()-1]].ss+1;
    if(!f) stree[u] = mp(nod,nod);
    nod = stree[u].ss+1;
    update(1,1,n,stree[u].ss,stree[u].ss,p[u]);
}

int main() {
    ll m, a, b;
    while(cin >> n >> m && !cin.eof()) {
        for(int i=1;i<=n;i++) cin >> p[i];
        for(int i=1;i<n;i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        initialize(1,1,n);
        dfs(1);
        for(int i=0;i<m;i++) {
            string s;
            cin >> s;
            if(s == "SOMA") {
                cin >> a;
                cout << sum(query(1,1,n,stree[a].ff,stree[a].ss)) << endl;
            } else {
                cin >> a >> b;
                update(1,1,n,stree[a].ff,stree[a].ss,b);
            }
        }
    }
    return 0;
}


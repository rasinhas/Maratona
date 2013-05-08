#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>
#include <deque>
#define all(v) (v).begin(),(v).end()
#define degree(v) adj[v].size()

using namespace std;

deque<int> L[15000]; //levels
deque<int> sons[20000]; //levels
deque<int> subtreeLabels[20000];
int pi[20000]; int label[20000]; int color[20000];
int n; deque<int> adj[20000]; int map[20000];
bool compare(int a, int b){
    return (subtreeLabels[a] < subtreeLabels[b]);
}
bool equals(int a, int b) {
    return (subtreeLabels[a] == subtreeLabels[b]);
}
int DFSVisit(int r, int l = 0){ //l is levels
    int v,h = 0; L[l].push_back(r);
    color[r] = 1;
    for(int i=0; i<adj[r].size(); i++) {
        v = adj[r][i];
        if (color[v]==0) {
            pi[v] = r; sons[r].push_back(v);
            h = max(h, DFSVisit(v,l+1));
        }
    }
    color[r] = 2;
    return h+1;
}
void GenerateMapping(int r1, int r2) {
    int u,v; map[r1] = r2-n;
    sort(all(sons[r1]),compare); sort(all(sons[r2]),compare);
    for(int i=0; i<sons[r1].size(); i++){
        u = sons[r1][i]; v = sons[r2][i]; GenerateMapping(u,v);
    }
}
bool RootedTreeIsomorphism(int r1, int r2) {
    for(int i=0; i<n; i++) L[i].clear();
    for(int i=0; i<2*n; i++) {
        pi[i] = -1; color[i] = 0; sons[i].clear();
        subtreeLabels[i].clear();
    }
    int h1 = DFSVisit(r1);
    int h2 = DFSVisit(r2);
    if (h1!=h2) return false;
    else {
        int h = h1-1;
        for (int i=0; i<L[h].size(); i++) label[L[h][i]] = 0;
        for (int i = h-1; i>=0; i--) {
            for (int j=0; j<L[i+1].size(); j++)
                subtreeLabels[pi[L[i+1][j]]].push_back(label[L[i+1][j]]);
            for (int j=0; j<L[i+1].size(); j++)
                sort(subtreeLabels[L[i+1][j]].begin(),
                        subtreeLabels[L[i+1][j]].end());
            sort(L[i].begin(), L[i].end(), compare);
            int actualLabel = 0;
            label[L[i][0]] = actualLabel;
            for (int j=1; j<L[i].size(); j++) {
                if (!equals(L[i][j], L[i][j-1])) actualLabel++;
                label[L[i][j]] = actualLabel;
            }
        }
        if (equals(r1, r2)) { GenerateMapping(r1,r2); return true; }
        else return false;
    }
}
deque<int> FindCenter(int k) //k=0 is tree 1, k=1 is tree 2
{
    deque<int> S, T;
    int r, u, v, cdeg[n]; r = n;
    for(int i=0; i<n;i++) {
        cdeg[i] = degree(i+k*n);
        if (cdeg[i] <=1 ) { S.push_back(i+k*n); r--; }
    }
    while (r>0) {
        T.clear();
        for(int i=0; i<S.size(); i++) {
            u = S[i];
            for(int j=0; j<adj[u].size(); j++) {
                v = adj[u][j]; cdeg[v-k*n]--;
                if (cdeg[v-k*n] == 1) {
                    T.push_back(v); r--;
                }
            }
        }
        S = T;
    }
    return S;
}
bool TreeIsomorphism() {
    deque<int> S1 = FindCenter(0);
    deque<int> S2 = FindCenter(1);
    if (S1.size() != S2.size()) return false;
    else {
        if (RootedTreeIsomorphism(S1[0],S2[0])) return true;
        else if (S1.size()>1) return RootedTreeIsomorphism(S1[0],S2[1]);
        else return false;
    }
}

int main()
{
    int i, a, b;
    while(scanf("%d", &n) != EOF)
    {
        for(i=0;i<2*n;i++) adj[i].clear();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d", &a, &b);
            a--;b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d", &a, &b);
            a--;b--;
            adj[a+n].push_back(b+n);
            adj[b+n].push_back(a+n);
        }
        if(TreeIsomorphism()) printf("S\n");
        else printf("N\n");
    }
    return 0;
}

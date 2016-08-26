#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>

// TLE -- aproximadamente 10.5s no Live archive e 55 no SPOJ BR
// Suffix array o(nlogn)

using namespace std;

const int maxn = 1020000;
int wx[maxn],wy[maxn],*x,*y,wss[maxn],wv[maxn];
int n,l,len[10000], ord;
char dic[10000][1010],s[maxn];
int sa[maxn],rank[maxn],lcp[maxn],id[maxn],dis[maxn];
vector <int> grafo[10001];

int vis[10100];
int dist[10100];
int sorta[10100];

bool cmp(int *r,int n,int a,int b,int l)
{
    return a+l<n && b+l<n && r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(char str[],int sa[],int rank[],int lcp[],int n,int m)
{
    char *s = str;
    int *x=wx, *y=wy, *t,p;
    int i, j, k;
    int v = l;
    for(i=0;i<m;i++) wss[i]=0;
    for(i=0;i<n;i++) wss[x[i]=s[i]]++;
    for(i=1;i<m;i++) wss[i]+=wss[i-1];
    for(i=n-1;i>=0;i--) sa[--wss[x[i]]]=i;
    for(j=1,p=1;p<n && j<n;j*=2,m=p)
    {
        for(i=n-j,p=0;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]-j>=0)y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wss[i]=0;
        for(i=0;i<n;i++) wss[wv[i]]++;
        for(i=1;i<m;i++) wss[i]+=wss[i-1];
        for(i=n-1;i>=0;i--) sa[--wss[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,i=1,x[sa[0]]=0;i<n;i++)
            x[sa[i]] = cmp(y,n,sa[i-1],sa[i],j)?p-1:p++;
    }
    for(i=0;i<n;i++) rank[sa[i]]=i;
    for(i=0,j=0,k=0;i<n;lcp[rank[i++]]=k)
        if(rank[i]>0)
            for(k?k--:0,j=sa[rank[i]-1];i+k < n && j+k < n && str[i+k]==str[j+k];k++);
}

void match()
{
    int i, a;
    for(i=n;i<l-1;i++)
    {
        if(dis[sa[i]] == len[id[sa[i]]])
        {
            a = i+1;
            while(lcp[a] >= len[id[sa[i]]])
            {
                //printf("%s é substring de %s\n", dic[id[sa[i]]], dic[id[sa[a]]]);
                grafo[id[sa[i]]].push_back(id[sa[a]]);
                a++;
                if(a >= l) break;
            }
            a = i;
            while(lcp[a] >= len[id[sa[i]]])
            {
                //printf("%s é substring de %s\n", dic[id[sa[i]]], dic[id[sa[a-1]]]);
                grafo[id[sa[i]]].push_back(id[sa[a-1]]);
                a--;
                if(a == -1) break;
            }
        }
    }
}

void topsort(int u)
{
    vis[u] = 1;
    for(int i=0;i<grafo[u].size();i++) if(!vis[grafo[u][i]]) topsort(grafo[u][i]);
    sorta[ord++] = u;
}

int main()
{
    int i, j, ret, val;
    while(scanf("%d", &n) && n)
    {
        l = 0;
        ord = 0;
        for(i=0;i<n;i++) grafo[i].clear();
        memset(vis,0,n*sizeof(int));
        memset(dist,0,n*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%s",dic[i]);
            len[i] = strlen(dic[i]);
            for(j=0;j<len[i];j++)
            {
                id[l] = i;
                dis[l] = len[i]-j;
                s[l++] = dic[i][j];
            }
            id[l] = n;
            s[l++] = '#';
        }
        s[l] = 0;
        da(s,sa,rank,lcp,l,128);
        for(i=n;i<l;i++) printf("id = %d -- lcp = %d -- dis = %d  -- len = %d -- sa = %d ------ %s\n", id[sa[i]], lcp[i], dis[sa[i]], len[id[sa[i]]], sa[i],  s+sa[i]);
        match();
        for(i=0;i<n;i++) if(!vis[i]) topsort(i);
        ret = 0;
        for(i=0;i<n;i++)
        {
            val = 0;
            for(j=0;j<grafo[sorta[i]].size();j++) val = max(val,dist[grafo[sorta[i]][j]]);
            if(!val) dist[sorta[i]] = 1;
            else dist[sorta[i]] = val+1;
            ret = max(ret, dist[sorta[i]]);
        }
        printf("%d\n", ret);
    }
    return 0;
}

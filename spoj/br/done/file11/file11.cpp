#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 1020000;
int wx[maxn],wy[maxn],*x,*y,wss[maxn],wv[maxn];
int l,len[10000];
char dic[10000][1010],s[maxn];
int sa[maxn],rank[maxn],lcp[maxn],id[maxn],dis[maxn];

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

int main()
{
    int i, j, n, curlcp, a;
    long long curset;
    set <long long> ret;
    stack <pair<int,long long> > st;
    while(scanf("%d", &n) && n)
    {
        l = 0;
        ret.clear();
        while(!st.empty()) st.pop();
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
            s[l++] = '!'+i;
        }
        s[l] = 0;
        lcp[l] = 0;
        da(s,sa,rank,lcp,l,128);
        //for(i=n;i<l;i++) printf("id = %d -- lcp = %d ------ %s\n", id[sa[i]], lcp[i], s+sa[i]);
        curlcp = 0;
        curset = 0;
        // achando subconjuntos com strings sozinhas
        for(i=n;i<l;i++)
        {
            if(dis[sa[i]] == len[id[sa[i]]])
            {
                if(lcp[i] < len[id[sa[i]]] && lcp[i+1] < len[id[sa[i]]]) ret.insert(1ll<<id[sa[i]]);
            }
        }
        // achando subconjuntos com interseções de string
        for(i=n;i<l;i++)
        {
            /*
            printf("pos=>%d; curlcp=>%d; curset=>%lld; stack.size=>%d\n",i-n,curlcp,curset,st.size());
            if(!st.empty())
            {
                printf("$top1=>%d; top2=>%lld\n", st.top().first,st.top().second);
            }
            */
            if(curlcp == 0 && lcp[i+1] > 0)
            {
                curlcp = lcp[i+1];
                curset |= (1ll<<id[sa[i]]);
            }
            else if(curlcp > 0 && lcp[i+1] > curlcp)
            {
                st.push(make_pair(curlcp,curset));
                curlcp = lcp[i+1];
                curset = 0 | (1ll<<id[sa[i]]);
            }
            else if(curlcp > 0 && lcp[i+1] == curlcp)
            {
                curset |= (1ll<<id[sa[i]]);
            }
            else if(curlcp > 0 && lcp[i+1] < curlcp)
            {
                curset |= (1ll<<id[sa[i]]);
                ret.insert(curset);
                //printf("@@%lld pos=>%d\n",curset, i-n);
                curlcp = lcp[i+1];
                while(!st.empty())
                {
                    if(curlcp < st.top().first)
                    {
                        curset |= st.top().second;
                        ret.insert(curset);
                        st.pop();
                    }
                    else if(curlcp == st.top().first)
                    {
                        curset |= st.top().second;
                        st.pop();
                    }
                    else break;
                }
                if(lcp[i+1] == 0) curset = 0;
            }
        }
        /*
        set <long long>::iterator it;
        for(it=ret.begin();it != ret.end();it++)
        {
            printf("### %d\n", *it);
            for(i=0;i<n;i++)
            {
                if(*it & (1ll<<i)) printf("$ %s\n", dic[i]);
            }
        }
        */
        printf("%d\n", (int)ret.size());
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 101000;
int wx[maxn],wy[maxn],*x,*y,wss[maxn],wv[maxn];
int l;
char dic[101000],s[maxn];
int sa[maxn],rank[maxn],lcp[maxn];

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
    int i, j, curlcp, last, len;
    int ret;
    while(scanf("%s", dic) && dic[0]!='*')
    {
        l = 0;
        ret = 0;
        len = strlen(dic);
        for(j=0;j<len;j++) s[l++] = dic[j];
        s[l++] = '#';
        s[l] = '\0';
        lcp[l] = 0;
        da(s,sa,rank,lcp,l,128);
        //for(i=1;i<l;i++) printf("$%d -- lcp = %d ------ %s\n", i, lcp[i], s+sa[i]);
        curlcp = 0;
        last = 0;
        for(i=1;i<l;i++)
        {
            if(lcp[i+1] > curlcp)
            {
                curlcp = lcp[i+1];
            }
            else if(lcp[i+1] < curlcp)
            {
                ret += (curlcp-last);
                curlcp = lcp[i+1];
                last = curlcp;
            }
        }
        printf("%d\n", ret);
        //printf("#######\n");
    }
    return 0;
}

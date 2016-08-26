#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 111111;
int wx[maxn],wy[maxn],*x,*y,wss[maxn],wv[maxn];
int l;
char s[maxn];
int sa[maxn], ran[maxn], lcp[maxn];

bool cmp(int *r,int n,int a,int b,int l)
{
    return a+l<n && b+l<n && r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(char str[],int sa[],int ran[],int lcp[],int n,int m)
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
    for(i=0;i<n;i++) ran[sa[i]]=i;
    for(i=0,j=0,k=0;i<n;lcp[ran[i++]]=k)
        if(ran[i]>0)
            for(k?k--:0,j=sa[ran[i]-1];i+k < n && j+k < n && str[i+k]==str[j+k];k++);
}

int main()
{
    int k;
    cin >> s;
    cin >> k;
    l = strlen(s);
    da(s,sa,ran,lcp,l,128);
    if(k > l*(l-1)) cout << "No such line." << endl;
    else
    {
        for(int i=0;i<l;i++)
        {
            if(k <= l-sa[i])
            {
                for(int j=sa[i];j<sa[i]+k;j++) cout << s[j];
                cout << endl;
                break;
            }
            k -= l-sa[i]; 
        }
    }
    return 0;
}

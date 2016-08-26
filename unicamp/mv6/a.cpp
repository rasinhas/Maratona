#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const int N=111;
const int M=11111;
const int K=N*M;

int n;
int wx[K], wy[K], wss[K], wv[K], *x, *y;
int l, len[N];
char s[K], dic[N][M];
int sa[K], rnk[K], lcp[K], id[K], dis[K];

bool cmp(int *r, int n, int a, int b, int l) { return a+l < n && b+l < n && r[a]==r[b] && r[a+l]==r[b+l]; }

void da(char str[], int sa[], int rnk[], int lcp[], int n, int m) {
    char *s = str;
    int *x = wx, *y = wy, *t, p;
    int i, j, k;
    int v = l;
    for(i=0;i<m;i++) wss[i]=0;
    for(i=0;i<n;i++) wss[x[i]=s[i]]++;
    for(i=1;i<m;i++) wss[i]+=wss[i-1];
    for(i=n-1;i>=0;i--) sa[--wss[x[i]]]=i;
    for(j=1,p=1;p<n && j<n;j*=2,m=p) {
        for(i=n-j,p=0;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]-j>=0) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wss[i]=0;
        for(i=0;i<n;i++) wss[wv[i]]++;
        for(i=1;i<m;i++) wss[i]+=wss[i-1];
        for(i=n-1;i>=0;i--) sa[--wss[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,i=1,x[sa[0]]=0;i<n;i++) x[sa[i]] = cmp(y,n,sa[i-1],sa[i],j)?p-1:p++;
    }
    for(i=0;i<n;i++) rnk[sa[i]]=i;
    for(i=0,j=0,k=0;i<n;lcp[rnk[i++]]=k) if(rnk[i]>0) for(k?k--:0,j=sa[rnk[i]-1];i+k<n&&j+k<n&&str[i+k]==str[j+k];k++);
}

int main() {
    while(scanf("%d", &n) && n) {
        l = 0;
        for(int i=0;i<n;i++) {
            scanf("%s", dic[i]);
            len[i] = strlen(dic[i]);
            for(int j=0;j<len[i];j++) {
                id[l] = i;
                dis[l] = len[i]-j;
                s[l++] = dic[i][j];
            }
            id[l] = n;
            s[l++] = '!'+i;
        }
        s[l] = 0;
        lcp[l] = 0;
        da(s,sa,rnk,lcp,l,128);
        //for(int i=n;i<l;i++) printf("%d || %d || %s\n", id[sa[i]], lcp[i], s+sa[i]);
        int curlcp = 0;
        ll curset = 0;
        set <ll> w;
        stack <pair<ll,int> > q;
        for(int i=n;i<l;i++) {
            if(dis[sa[i]] == len[id[sa[i]]] && lcp[i] < len[id[sa[i]]] && lcp[i+1] < len[id[sa[i]]]) {
                w.insert(1ll<<id[sa[i]]);
            }
        }
        // percorrendo o lcp
        for(int i=n;i<l;i++) {
            if(curlcp == 0) {
                if(lcp[i+1] == 0) w.insert(1ll<<id[sa[i]]);
                else curset = (1ll<<id[sa[i]]);
            } else {
                if(lcp[i+1] > curlcp) {
                    q.push(mp(curset,curlcp));
                    curset = (1ll<<id[sa[i]]);
                } else if(lcp[i+1] < curlcp) {
                    curset |= (1ll<<id[sa[i]]);
                    w.insert(curset);
                    while(!q.empty() && q.top().ss >= lcp[i+1]) {
                        curset |= q.top().ff;
                        if(lcp[i+1] < q.top().ss) w.insert(curset);
                        q.pop();
                    }
                } else curset |= (1ll<<id[sa[i]]);
            }
            curlcp = lcp[i+1];
        }
        cout << (int)w.size() << endl;
    }
    return 0;
}

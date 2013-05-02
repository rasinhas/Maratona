#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#define MAXN 1020000
#define GetI() ( SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2 )

using namespace std;

// Accepted chorado -- 7.5s no Live archive e 39.5s no SPOJ BR
// Suffix Array o(n)

char frase[MAXN];
int N, v[MAXN]; // tamanho da string atual e representacao em inteiros da string
int SA[MAXN], SAR[MAXN]; // suffix array e suffix array "reverso"
int LCP[MAXN]; // longest common prefix
const char FIRST_CHAR = ','; // primeiro char do alfabeto (tabela ASCII)
const char LAST_CHAR = 'z'; // ultimo char do alfabeto (tabela ASCII)
const int ALF = LAST_CHAR - FIRST_CHAR + 1; // tamanho do alfabeto
int CUR_ALF; // tamanho do alfabeto da string atual
vector<int> occ[ALF]; // occ[i] - posicoes em que o char i aparece

vector <int> grafo[10001];

int vis[10100];
int dist[10100];
int sorta[10100];
int n,l,len[10000], ord,id[MAXN],dis[MAXN];
char dic[10000][1010],s[MAXN];


bool leq(int a1, int a2, int b1, int b2)
{
    return(a1<b1 || a1==b1 && a2<=b2);
}

bool leq(int a1, int a2, int a3, int b1, int b2, int b3)
{
    return(a1<b1 || a1==b1 && leq(a2, a3, b2, b3));
}

static void radix_pass(int* a, int* b, int* r, int n, int K)
{
    int *c=new int[K+1], i, sum=0, t;
    for(i=0; i<=K; i++) c[i]=0;
    for(i=0; i<n; i++) c[r[a[i]]]++;
    for(i=0; i<=K; i++)
    {
        t=c[i];
        c[i]=sum;
        sum+=t;
    }
    for(i=0; i<n; i++) b[c[r[a[i]]]++]=a[i];
    delete []c;
}

void suffix_array(int* s, int* SA, int n, int K)
{
    int i, j, p, t, k, n0=(n+2)/3, n1=(n+1)/3, n2=n/3, n02=n0+n2, *s12=new int[n02+3], *SA12=new int[n02+3], *s0=new int[n0], *SA0=new int[n0];
    int name=0, c0=-1, c1 =-1, c2=-1;
    for(i=0, j=0; i<n+(n0-n1); i++)
        if(i%3!=0)
            s12[j++]=i;
    s12[n02]=s12[n02+1]=s12[n02+2]=SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
    radix_pass(s12, SA12, s+2, n02, K);
    radix_pass(SA12, s12, s+1, n02, K);
    radix_pass(s12, SA12, s, n02, K);
    for(i=0; i<n02; i++)
    {
        if(s[SA12[i]]!=c0 || s[SA12[i]+1]!=c1 || s[SA12[i]+2]!=c2)
        {
            name++;
            c0=s[SA12[i]];
            c1=s[SA12[i]+1];
            c2=s[SA12[i]+2];
        }
        if(SA12[i]%3==1) s12[SA12[i]/3]=name;
        else s12[SA12[i]/3+n0]=name;
    }
    if(name<n02)
    {
        suffix_array(s12, SA12, n02, name);
        for(i=0; i<n02; i++) s12[SA12[i]]=i+1;
    }
    else
        for(i=0; i<n02; i++) SA12[s12[i]-1]=i;
    j=0;
    for(i=0; i<n02; i++)
        if(SA12[i]<n0)
            s0[j++]=3*SA12[i];
    radix_pass(s0, SA0, s, n0, K);
    for(p=0, t=n0-n1, k=0; k<n; k++)
    {
        i=GetI();
        j=SA0[p];
        if(SA12[t]<n0 ? leq(s[i], s12[SA12[t]+n0], s[j], s12[j/3]) : leq(s[i], s[i+1], s12[SA12[t]-n0+1], s[j], s[j+1], s12[j/3+n0]))
        {
            SA[k]=i;
            t++;
            if(t==n02)
                for(k++; p<n0; p++, k++)
                    SA[k]=SA0[p];
        }
        else
        {
            SA[k]=j;
            p++;
            if(p==n0)
                for(k++; t<n02; t++, k++)
                    SA[k]=GetI();
        }
    }
    delete [] s12; delete [] SA12; delete [] SA0; delete [] s0;
}

void initialize(const string & s)
{
    int cnt=1, i, j;
    N=s.length();
    memset(v, 0, sizeof(v));
    for(i=0; i<ALF; i++) occ[i].clear();
    for(i=0; i<N; i++) occ[s[i]-FIRST_CHAR].push_back(i);
    for(i=0; i<ALF; i++)
        if(!occ[i].empty())
        {
            for(j=0; j<occ[i].size(); j++)
                v[occ[i][j]]=cnt;
            cnt++;
        }
    CUR_ALF=cnt-1;
}

//LCP comparando termos i e i+1 (diferente da definição vista que compara os termos i e i-1)
void lcp(const string & s)
{
    int i, h=0, r;
    for(i=0; i<N; i++) SAR[SA[i]]=i;
    for(i=0; i<N; i++)
        if(SAR[i]+1<N)
        {
            r=SA[SAR[i]+1];
            while(r+h<N && i+h<N && s[r+h]==s[i+h]) h++;
            LCP[SAR[i]]=h;
            if(h>0) h--;
        }
}

void match()
{
    int i, a;
    for(i=n;i<l-1;i++)
    {
        if(dis[SA[i]] == len[id[SA[i]]])
        {
            a = i;
            while(LCP[a] >= len[id[SA[i]]])
            {
                //printf("%s é substring de %s\n", dic[id[SA[i]]], dic[id[SA[a+1]]]);
                grafo[id[SA[i]]].push_back(id[SA[a+1]]);
                a++;
                if(a == N-1) break;
            }
            a = i-1;
            while(LCP[a] >= len[id[SA[i]]])
            {
                //printf("%s é substring de %s\n", dic[id[SA[i]]], dic[id[SA[a]]]);
                grafo[id[SA[i]]].push_back(id[SA[a]]);
                a--;
                if(a <= 1) break;
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
        initialize((string)s);
        suffix_array(v,SA,N,CUR_ALF);
        lcp((string)s);
        //for(i=n;i<l;i++) printf("lcp = %d ------ %s\n", LCP[i], s+SA[i]);
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

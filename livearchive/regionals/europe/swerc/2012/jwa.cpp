#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

typedef struct vertex
{
    int value;
    int op1, op2;
    char oper;
    vertex(int v, int o1, int o2, char op)
    {
        value = v;
        op1 = o1;
        op2 = o2;
        oper = op;
    }
    vertex() { value = -1; op1 = -1; op2 = -1; oper = '.'; }
} vertex;

int mod(int a) { return a > 0 ? a : -a; }

//armazena a posição no vector de vértices de cada número - 1
int vis[10001000];
int t, k;
stack <vertex> s;
vector <vertex> l;

int bfs()
{
    int  u, v;
    int close = INF;
    queue <vector<int> > q;
    vector <int> p, r;
    for(int i=0;i<6;i++) p.push_back(l[i].value);
    q.push(p);
    p.clear();
    while(!q.empty())
    {
        r = q.front();
        q.pop();
        for(int i=0;i<r.size();i++)
        {
            for(int j=i+1;j<r.size();j++)
            {
                if(j != i)
                {
                    for(int m=0;m<r.size();m++) if(m != i && m != j) p.push_back(r[m]);
                    u = r[i];
                    v = r[j];
                    if(u*v < 10000000)
                    {
                        l.push_back(vertex(u*v,u,v,'*'));
                        p.push_back(u*v);
                        q.push(p);
                        vis[u*v] = k++;
                        p.pop_back();
                        if(mod(u*v-t) < mod(close-t)) close = u*v;
                        printf("!%d\n", u*v);
                    }
                    if(u+v < 10000000)
                    {
                        l.push_back(vertex(u+v,u,v,'+'));
                        p.push_back(u+v);
                        q.push(p);
                        vis[u+v] = k++;
                        p.pop_back();
                        if(mod(u+v-t) < mod(close-t)) close = u+v;
                        printf("@%d\n", u+v);
                    }
                    if(u-v)
                    {
                        l.push_back(vertex(mod(u-v),max(u,v),min(u,v),'-'));
                        p.push_back(mod(u-v));
                        q.push(p);
                        vis[mod(u-v)] = k++;
                        p.pop_back();
                        if(mod(mod(u-v)-t) < mod(close-t)) close = mod(u-v);
                        printf("#%d\n", mod(u-v));
                    }
                    if((max(u,v)%min(u,v)) == 0) 
                    {
                        l.push_back(vertex(max(u,v)/min(u,v),max(u,v),min(u,v),'/'));
                        p.push_back(max(u,v)/min(u,v));
                        q.push(p);
                        vis[max(u,v)/min(u,v)] = k++;
                        p.pop_back();
                        if(mod((max(u,v)/min(u,v))-t) < mod(close-t)) close = max(u,v)/min(u,v);
                        printf("$%d\n", max(u,v)/min(u,v));
                    }
                    if(vis[t]) return t;
                    p.clear();
                }
            }
        }
    }
    return close;
}

void track(int a)
{
    vertex v;
    v = l[vis[a]-1];
    if(v.op1 != -1 && v.op2 != -1)
    {
        s.push(v);
        track(v.op1);
        track(v.op2);
    }
}

int main()
{
    int c, n, ap;
    vertex v;
    scanf("%d", &c);
    for(int i=0;i<c;i++)
    {
        k = 1;
        memset(vis,0,sizeof(vis));
        l.clear();
        while(!s.empty()) s.pop();
        for(int j=0;j<6;j++)
        {
            scanf("%d", &n);
            if(!vis[n]) vis[n] = k;
            l.push_back(vertex(n,-1,-1,'.'));
            k++;
        }
        scanf("%d", &t);
        printf("Target: %d\n", t);
        ap = bfs();
        track(ap);
        while(!s.empty())
        {
            v = s.top();
            printf("%d %c %d = %d\n", v.op1, v.oper, v.op2, v.value);
            s.pop();
        }
        printf("Best approx: %d\n\n", ap);
    }
    return 0;
}

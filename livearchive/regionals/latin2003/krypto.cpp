#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define INF 1e9

using namespace std;

typedef struct {
    int x;
    int y;
} ponto;

typedef struct {
    int obs;
    ponto p;
} vertice;

typedef struct {
    ponto p1;
    ponto p2;
} obstaculo;

ponto pontos[200];
obstaculo obs[100];
vertice vertices[200];
vector<pair<int, double> > grafo[200];
int vis[200][100], m;
double d[200][100];

int aprox(double u)
{
    if(u-(int)u>0.5) return (int)u+1;
    return (int)u;
}

void dijkstra(int s, int t)
{
    int u, v, w, i;
    d[s][t]=0.0;
    priority_queue<pair<double, pair<int, int> > > q;
    q.push(make_pair(-d[s][t], make_pair(s, t)));
    while(!q.empty())
    {
        u=q.top().second.first;
        w=q.top().second.second;
        q.pop();
        if(vis[u][w]) continue;
        vis[u][w]=1;
        for(i=0; i<grafo[u].size(); i++)
        {
            v=grafo[u][i].first;
            if(u>=2*(m+1) && v>=2*(m+1))
            {
                if(w-1>=0 && d[v][w-1]>d[u][w]+grafo[u][i].second)
                {
                    d[v][w-1]=d[u][w]+grafo[u][i].second;
                    q.push(make_pair(-d[v][w-1], make_pair(v, w-1)));
                }
            }
            else
            {
                if(d[v][w]>d[u][w]+grafo[u][i].second)
                {
                    d[v][w]=d[u][w]+grafo[u][i].second;
                    q.push(make_pair(-d[v][w], make_pair(v, w)));
                }
            }
        }
        if(u==1) return;
    }
}

int direction(ponto pi, ponto pj, ponto pk)
{
    return ((pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y));
}

int on_segment(ponto pi, ponto pj, ponto pk)
{
    if((pk.x>=min(pi.x, pj.x) && pk.x<=max(pi.x, pj.x)) && (pk.y>=min(pi.y, pj.y) && pk.y<=max(pi.y, pj.y))) return 1;
    return 0;
}

int segments_intersect(ponto p1, ponto p2, ponto p3, ponto p4)
{
    int d1, d2, d3, d4;
    d1=direction(p3, p4, p1);
    d2=direction(p3, p4, p2);
    d3=direction(p1, p2, p3);
    d4=direction(p1, p2, p4);
    if(((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3>0 && d4<0) || (d3<0 && d4>0))) return 1;
    else if(d1==0 && on_segment(p3, p4, p1)) return 1;
    else if(d2==0 && on_segment(p3, p4, p2)) return 1;
    else if(d3==0 && on_segment(p1, p2, p3)) return 1;
    else if(d4==0 && on_segment(p1, p2, p4)) return 1;
    return 0;
}

int main()
{
    int i, j, k, xi, yi, xf, yf, aux, flag, dx, dy, t, c;
    ponto cabine;
    double dist, resp;
    while(scanf("%d %d %d", &t, &m, &c) && (t || m || c))
    {
        aux=2;
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d %d", &obs[i].p1.x, &obs[i].p1.y, &obs[i].p2.x, &obs[i].p2.y);
            vertices[aux].obs=i;
            vertices[aux].p.x=obs[i].p1.x;
            vertices[aux++].p.y=obs[i].p1.y;
            vertices[aux].obs=i;
            vertices[aux].p.x=obs[i].p2.x;
            vertices[aux++].p.y=obs[i].p2.y;
        }
        for(i=0; i<c; i++)
        {
            scanf("%d %d", &cabine.x, &cabine.y);
            vertices[aux].obs=-1;
            vertices[aux].p.x=cabine.x;
            vertices[aux++].p.y=cabine.y;
        }
        scanf("%d %d %d %d", &xi, &yi, &xf, &yf);
        vertices[0].obs=-1;
        vertices[0].p.x=xi;
        vertices[0].p.y=yi;
        vertices[1].obs=-1;
        vertices[1].p.x=xf;
        vertices[1].p.y=yf;
        for(i=0; i<aux; i++)
        {
            for(j=0; j<=t; j++)
            {
                d[i][j]=INF;
                vis[i][j]=0;
            }
            for(j=i+1; j<aux; j++)
            {
                flag=0;
                for(k=0; k<m; k++)
                {
                    if(vertices[i].obs==k || vertices[j].obs==k) continue;
                    if(segments_intersect(vertices[i].p, vertices[j].p, obs[k].p1, obs[k].p2))
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                {
                    if(i>=2*(m+1) && j>=2*(m+1))
                    {
                        grafo[i].push_back(make_pair(j, 0.0));
                        grafo[j].push_back(make_pair(i, 0.0));
                    }
                    else
                    {
                        dx=vertices[i].p.x-vertices[j].p.x;
                        dy=vertices[i].p.y-vertices[j].p.y;
                        dist=dx*dx+dy*dy;
                        dist=sqrt(dist);
                        grafo[i].push_back(make_pair(j, dist));
                        grafo[j].push_back(make_pair(i, dist));
                    }
                }
            }
        }
        dijkstra(0, t);
        resp=INF;
        for(i=0; i<=t; i++) resp=min(resp, d[1][i]);
        printf("%d\n", aprox(resp));
        for(i=0; i<aux; i++) grafo[i].clear();
    }
    return 0;
}

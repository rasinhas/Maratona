#include <stdio.h>
#include <algorithm>
#define INF 1000000000

using namespace std;

int a, b, n, x[500], y[500];

//FIXME - Acho q essa questao n foi terminada
void borda(int x1, int y1, int x2, int y2, int minx, int miny, int maxx, int maxy)
{
    int l1, l2, i, minx2, miny2, maxx2, maxy2;
    l1=y2-y1;
    l2=minx-x1;
    if(l1>l2) swap(l1, l2);
    if(l1>a || (l1==a && l2>b))
    {
        a=l1;
        b=l2;
    }
    l1=y2-y1;
    l2=x2-maxx;
    if(l1>l2) swap(l1, l2);
    if(l1>a || (l1==a && l2>b))
    {
        a=l1;
        b=l2;
    }
    l1=x2-x1;
    l2=y2-maxy;
    if(l1>l2) swap(l1, l2);
    if(l1>a || (l1==a && l2>b))
    {
        a=l1;
        b=l2;
    }
    l1=x2-x1;
    l2=miny-y1;
    if(l1>l2) swap(l1, l2);
    if(l1>a || (l1==a && l2>b))
    {
        a=l1;
        b=l2;
    }
    if(minx==maxx || miny==maxy) return;
    minx2=miny2=INF;
    maxx2=maxy2=-INF;
    for(i=0; i<n; i++)
        if(x[i]<maxx && x[i]>minx && y[i]<maxy && y[i]>miny)
        {
            if(x[i]>maxx2) maxx2=x[i];
            if(x[i]<minx2) minx2=x[i];
            if(y[i]>maxy2) maxy2=y[i];
            if(y[i]<miny2) miny2=y[i];
        }
    borda(minx, miny, maxx, maxy, minx2, miny2, maxx2, maxy2);
}

int main()
{
    int x1, y1, x2, y2, i, minx, miny, maxx, maxy;
    while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2) && (x1 || y1 || x2 || y2))
    {
        scanf("%d", &n);
        minx=miny=INF;
        a=b=0;
        maxx=maxy=-INF;
        for(i=0; i<n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
            if(x[i]>maxx) maxx=x[i];
            if(x[i]<minx) minx=x[i];
            if(y[i]>maxy) maxy=y[i];
            if(y[i]<miny) miny=y[i];
        }
        borda(x1, y1, x2, y2, minx, miny, maxx, maxy);
        printf("%d %d\n", a, b);
    }
    return 0;
}

#include <iostream>
#include <ctype.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define EPS 1e-6

using namespace std;

typedef pair <int, int> pii;

double xc, yc, r2;
typedef struct
{
    double x, y;
}Point;

void find_circle(Point *p1, Point *p2, Point *p3) {
    double x1, y1, x2, y2, x3, y3;
    x1 = p1->x, y1 = p1->y;
    x2 = p2->x, y2 = p2->y;
    x3 = p3->x, y3 = p3->y;
    if(fabs(x1-x2) < EPS) swap(y3,y2), swap(x3,x2);
    yc = ((x1-x2)*(x1*x1+y1*y1-x3*x3-y3*y3)-(x1-x3)*(x1*x1+y1*y1-x2*x2-y2*y2))/(2*((y2-y1)*(x1-x3)-(y3-y1)*(x1-x2)));
    xc = (x1*x1+y1*y1-x2*x2-y2*y2+2*yc*(y2-y1))/(2*(x1-x2));
    r2 = (xc-x1)*(xc-x1)+(yc-y1)*(yc-y1);
}


int main()
{
    int i, j, k, l, n, ret, cnt;
    double x, y;
    Point pontos[101];
    while(scanf("%d", &n) && n)
    {
        ret = 2;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf", &x, &y);
            pontos[i].x = x;
            pontos[i].y = y;
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if(pontos[i].x == pontos[j].x && pontos[j].x == pontos[k].x) continue;
                    if(pontos[i].y == pontos[j].y && pontos[j].y == pontos[k].y) continue;
                    find_circle(&pontos[i], &pontos[j], &pontos[k]);
                    cnt = 0;
                    for(l=0;l<n;l++) if(fabs((xc-pontos[l].x)*(xc-pontos[l].x)+(yc-pontos[l].y)*(yc-pontos[l].y) - r2) < EPS) cnt++;
                    ret = max(ret,cnt);
                }
            }
        }
        printf("%d\n", ret);
    }
	return 0;
}

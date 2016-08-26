#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        int x1,x2,y1,y2,dx,dy;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int s = max(x1,max(x2,max(y1,y2)));
        dx = x1-x2;
        dy = y2-y1;
        int nx1, nx2, ny1, ny2;
        if(dy > 0)
        {
            nx1 = 0;
            nx2 = dy;
        }
        else 
        {
            nx1 = s;
            nx2 = s+dy;
        }
        if(dx > 0)
        {
            ny1 = 0;
            ny2 = dx;
        }
        else 
        {
            ny1 = s;
            ny2 = s+dx;
        }
        printf("Case %d: %d %d %d %d\n", t, nx1, ny1, nx2, ny2);
    }
    return 0;
}

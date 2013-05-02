#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    int i, j, r, c, k;
    int n, m, minimo, val, init, end;
    int ac[301][301];
    char ass[301][301], p;
    while(scanf("%d %d %d", &r, &c, &k) && r)
    {
        minimo = INF;
        for(i=0;i<r;i++) 
        {
            for(j=0;j<c;j++)
            {
                scanf(" %c", &ass[i][j]);
            }
            if(i == 0) ac[i][0] = 0;
            else ac[i][0] = ac[i-1][0];
            if(ass[i][0] == '.') ac[i][0]++;
            for(j=1;j<c;j++)
            {
                if(i == 0) ac[i][j] = ac[i][j-1];
                else ac[i][j] = ac[i][j-1] + ac[i-1][j] - ac[i-1][j-1];
                if(ass[i][j] == '.') ac[i][j]++;
            }
        }

        // complexidade o(2*r²*c)
        for(i=0;i<r;i++)
        {
            for(j=i;j<r;j++)
            {
                init = 0;
                end = 0;
                if(i == 0 && ac[j][c-1] < k) continue;
                else if(i > 0 && ac[j][c-1]-ac[i-1][c-1] < k) continue;
                while(init+end <= 2*(c-1))
                {
                    val = 0;
                    if(init != 0) val += ac[j][init-1];
                    if(i != 0) val += ac[i-1][end];
                    if(i != 0 && init != 0) val -= ac[i-1][init-1];
                    if(ac[j][end] - val >= k) minimo = min(minimo,(j-i+1)*(end-init+1));
                    if(end < c-1)
                    {
                        if(ac[j][end] - val >= k)
                        {
                            if(init == end) break;
                            else init++;
                        }
                        else end++;
                    }
                    else init++;
                }
            }
        }
        printf("%d\n", minimo);
    }
	return 0;
}

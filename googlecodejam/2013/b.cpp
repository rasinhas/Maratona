#include <iostream>
#include <cstdio>

using namespace std;

int lawn[100][100];
int n, m;

bool check_l(int u, int v)
{
    int fail = 0;
    for(int i=0;i<m;i++)
    {
        if(lawn[u][i] > lawn[u][v]) fail = 1;
        if(fail) break;
    }
    return !fail;
}

bool check_c(int u, int v)
{
    int fail = 0;
    for(int i=0;i<n;i++)
    {
        if(lawn[i][v] > lawn[u][v]) fail = 1;
        if(fail) break;
    }
    return !fail;
}

int main()
{
    int T, fail;
    scanf("%d", &T);
    for(int t=0;t<T;t++)
    {
        fail = 0;
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d", &lawn[i][j]);
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<m;j++)
            {
                if(!check_l(i,j) && !check_c(i,j)) fail = 1;
                if(fail) break;
            }
            if(fail) break;
        }
        printf("Case #%d: ", t+1);
        if(fail) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

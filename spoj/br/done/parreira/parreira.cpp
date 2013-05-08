#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> diagonal[1010];
int mat[501][501], diagl[1000];

int main()
{
    int i, j, n, m, q, l, u, h, maximo, low, up;
    while(scanf("%d %d", &n, &m) && (n || m))
    {
        for(i=0; i<n+m-1; i++) diagonal[i].clear();
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                scanf("%d", &h);
                if(diagonal[n+j-i-1].empty()) diagl[n+j-i-1] = i; 
                diagonal[n+j-i-1].push_back(h);
                mat[i][j] = h;
            }
        scanf("%d", &q);
        for(i=0; i<q; i++)
        {
            maximo=0;
            scanf("%d %d", &l, &u);
            for(j=0; j<n; j++)
            {
                low=lower_bound(mat[j], mat[j]+m, l)-mat[j];
                if(low < m)
                {
                    up=upper_bound(diagonal[n+low-j-1].begin(), diagonal[n-j+low-1].end(), u)-diagonal[n-j+low-1].begin();
                    if(low > j) maximo = max(maximo,up-j);
                    else maximo = max(maximo, up-low);
                }
            }
            printf("%d\n", maximo);
        }
        printf("-\n");
    }
    return 0;
}

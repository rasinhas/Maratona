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
    int i, n, j, k;
    int val[300];
    double f, ret;
    double dp[300][300];
    int a[300][300];
    while(scanf("%d %lf", &n, &f) && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d", &val[i]);
            // a[i][i] e a area da regiao i
            a[i][i] = val[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                // a[i][j] e a area da regiao i ate a regiao j
                if(i != (j+i)%n) a[i][(j+i)%n] = a[i][(j+i+n-1)%n] + a[(j+i)%n][(j+i)%n];
                // inicializa dp como infinito
                dp[i][j] = INF;

            }
        }
        ret = INF;
        // se so tiver 1 terreno o resultado e zero
        if(n == 1) ret = 0.0;
        // para fazer o terreno sozinho não custa nada
        for(i=0;i<n;i++) dp[i][i] = 0;
        for(i=1;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<i;k++)
                {
                    // percorro as diagonais paralelas a diagonal principal da matriz dp
                    // i e o tamanho do intervalo. usa-se aritmetica modular por causa da
                    // circularidade do problema.
                    // dp[a][c] => menor valor da soma da dp[a][b] + dp[b+1][c] + max(a[a][b],a[a+1][c])
                    dp[j][(j+i)%n] = min(dp[j][(j+i)%n], dp[j][(j+k)%n]+dp[(j+k+1)%n][(j+i)%n]+max(a[j][(j+k)%n],a[(j+k+1)%n][(j+i)%n]));
                    if(i == n-1) ret = min(ret, dp[j][(j+i)%n]);
                }
            }
        }
        printf("%.2lf\n", f*ret);
    }
	return 0;
}

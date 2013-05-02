#include <stdio.h>
#include <string.h>


int main()
{
    int i, n, sum, cnt, j, k, p;
    int vis[10100], seq[10100];
    scanf("%d", &k);
    for(j=0;j<k;j++)
    {
        scanf("%d", &n);
        sum = 0;
        memset(vis,0,(n+1)*sizeof(int));
        for(i=1;i<=n;i++)
        {
            scanf("%d", &seq[i]);
        }
        for(i=1;i<=n;i++)
        {
            p = i;
            if(vis[p]) continue;
            cnt = 0;
            while(!vis[p])
            {
                vis[p] = 1;
                p = seq[p];
                cnt++;
            }
            sum += cnt-1;
        }
        printf("%d\n", sum);
    }
    return 0;
}

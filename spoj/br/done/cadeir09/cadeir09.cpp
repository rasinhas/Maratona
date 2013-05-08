#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    int n, m, i, j, c1, l1, p, sum, cnt;
    int seq[300], s[300][300], vis[300];
    vector <pair<int,int> > lsol;
    vector <pair<int,int> > csol;
    scanf("%d%d", &n, &m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d", &s[i][j]);
            if(s[i][j] == 1)
            {
                l1 = i;
                c1 = j;
            }
        }
    }
    memset(vis,0,(m+1)*sizeof(int));
    sum = 0;
    for(i=0;i<m;i++) seq[i+1] = s[l1][i];
    for(i=1;i<=m;i++)
    {
        vis[i] = 1;
        p = seq[i];
        cnt = 1;
        while(!vis[p])
        {
            vis[p] = 1;
            csol.push_back(make_pair(p,seq[p]));
            p = seq[p];
            cnt++;
        }
        sum += cnt-1;
    }
    memset(vis,0,(n+1)*sizeof(int));
    for(i=0;i<n;i++) seq[i+1] = s[i][c1]/m + (m > 1 ? 1 : 0);
    for(i=1;i<=n;i++)
    {
        vis[i] = 1;
        p = seq[i];
        cnt = 1;
        while(!vis[p])
        {
            vis[p] = 1;
            lsol.push_back(make_pair(p,seq[p]));
            p = seq[p];
            cnt++;
        }
        sum += cnt-1;
    }
    if(lsol.empty() && csol.empty()) printf("0\n");
    else
    {
        printf("%d\n", sum);
        for(i=lsol.size()-1;i>=0;i--)
        {
            printf("L %d %d\n", lsol[i].first, lsol[i].second);
        }
        for(i=csol.size()-1;i>=0;i--)
        {
            printf("C %d %d\n", csol[i].first, csol[i].second);
        }
    }
    return 0;
}

#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

bool compara(pair<int,int> a, pair<int,int> b)
{
    if(a.first > b.first) return true;
    else if(a.first == b.first)
    {
        if(a.second < b.second) return true;
        else return false;
    }
    else return false;
}

int main()
{
    int i, j, g, p, s, pos, pont, l, m, k;
    int pilotos[110][110];
    int pontuacao[110];
    vector <pair<int,int> > final;
    while(scanf("%d%d", &g, &p) && g)
    {
        for(i=0;i<101;i++) for(j=0;j<101;j++) pilotos[i][j]=0;
        for(i=0;i<g;i++)
        {
            for(j=1;j<=p;j++)
            {
                scanf("%d", &pos);
                pilotos[j][pos]++;
            }
        }
        scanf("%d", &s);
        for(i=0;i<s;i++)
        {
            scanf("%d", &k);
            for(j=1;j<=k;j++)
            {
                scanf("%d", &pontuacao[j]);
            }
            for(j=1;j<=p;j++)
            {
                pont=0;
                for(l=1;l<=k;l++) pont+=(pilotos[j][l]*pontuacao[l]);
                final.push_back(make_pair(pont,j));
            }
            sort(final.begin(),final.end(),compara);
            m = final[0].first;
            for(l=0;m==final[l].first;l++) printf("%d ",final[l].second);
            printf("\n");
            final.clear();
        }
    }
    return 0;
}

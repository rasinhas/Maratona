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

vector <int> grafo[4500], grafot[4500];
int vis[4500], visinv[4500], ordem[4500], ord, cc;

void dfsinv(int u)
{
    visinv[u] = 1;
    for(int i=0;i<grafot[u].size();i++) if(!visinv[grafot[u][i]]) dfsinv(grafot[u][i]);
    ordem[ord++] = u;
}

void dfs(int u)
{
    vis[u] = cc;
    for(int i=0;i<grafo[u].size();i++) if(!vis[grafo[u][i]]) dfs(grafo[u][i]);
}

int main()
{
    int i, n, teste=1;
    int flag1, flag2, ret, cnt;
    string str1, str2;
    map <string,int> id;
    while(scanf("%d", &n) != EOF)
    {
        id.clear();
        ord = 0;
        cnt = 0;
        cc = 1;
        for(i=0;i<n;i++)
        {
            flag1 = flag2 = 0;
            cin >> str1;
            if(str1[0] == '!')
            {
                flag1 = 1;
                str1.erase(str1.begin());
            }
            if(!id.count(str1))
            {
                id[str1] = cnt++;
            }
            cin >> str2;
            if(str2[0] == '!')
            {
                flag2 = 1;
                str2.erase(str2.begin());
            }
            if(!id.count(str2))
            {
                id[str2] = cnt++;
            }
            grafo[id[str1]+2000*(1-flag1)].push_back(id[str2]+2000*flag2);
            grafo[id[str2]+2000*(1-flag2)].push_back(id[str1]+2000*flag1);
            grafot[id[str1]+2000*flag1].push_back(id[str2]+2000*(1-flag2));
            grafot[id[str2]+2000*flag2].push_back(id[str1]+2000*(1-flag1));
        }
        /*
        map<string, int>::iterator it;
        for(it=id.begin();it!=id.end();it++)
        {
            cout << (*it).first << " " << (*it).second << endl;
        }
        */
        for(i=0;i<cnt;i++) if(!visinv[i]) dfsinv(i);
        for(i=0;i<cnt;i++) if(!visinv[2000+i]) dfsinv(2000+i);
        for(i=2*cnt-1;i>=0;i--) if(!vis[ordem[i]]) 
        {
            dfs(ordem[i]);
            cc++;
        }
        /*
        for(i=0;i<cnt;i++)
        {
            printf("##%d ", i);
            for(int j=0;j<grafo[i].size();j++) printf("%d ", grafo[i][j]);
            printf("\n");
        }
        for(i=0;i<cnt;i++)
        {
            printf("##%d ", 2000+i);
            for(int j=0;j<grafo[2000+i].size();j++) printf("%d ", grafo[2000+i][j]);
            printf("\n");
        }
        */
        ret = 1;
        for(i=0;i<cnt;i++)
        {
            if(vis[i] == vis[i+2000])
            {
                ret = 0;
                break;
            }
        }
        printf("Instancia %d\n", teste++);
        if(ret) printf("sim\n\n");
        else printf("nao\n\n");
        for(i=0;i<cnt;i++)
        {
            vis[i] = 0;
            vis[i+2000] = 0;
            visinv[i] = 0;
            visinv[i+2000] = 0;
            grafo[i].clear();
            grafo[2000+i].clear();
            grafot[i].clear();
            grafot[2000+i].clear();
        }
    }
	return 0;
}

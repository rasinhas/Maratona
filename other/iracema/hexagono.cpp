#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int p[10][10];
int ord[10];

void rotate(int a)
{
    swap(p[a][0],p[a][1]);
    swap(p[a][0],p[a][2]);
    swap(p[a][0],p[a][3]);
    swap(p[a][0],p[a][4]);
    swap(p[a][0],p[a][5]);
}

void print()
{
    for(int i=0;i<7;i++) printf("%d ", ord[i]);
    printf("\n");
}

bool dfs(int k, int used)
{
    int r = 0;
    for(int i=0;i<7;i++)
    {
        if(!((1<<i) & used))
        {
            while(p[i][(k+2)%6] != p[ord[0]][(k+5)%6]) rotate(i);
            ord[k] = i;
            if(k > 1)
            {
                if(p[i][(k+3)%6] == p[ord[k-1]][k%6]) 
                {
                    if(k == 6 &&p[i][1] == p[ord[1]][4]) return 1;
                    r = dfs(k+1,used+(1<<i));
                }
            }
            else r = dfs(k+1,used+(1<<i));
            if(r) return r;
        }
    }
    return 0;
}

int main()
{
    int n, s, i;
    cin >> n;
    for(int t=1;t<=n;t++)
    {
        for(i=0;i<7;i++) for(int j=0;j<6;j++) cin >> p[i][j];
        s = 0;
        for(i=0;i<7;i++)
        {
            while(p[i][0] != 1) rotate(i);
            ord[0] = i;
            if(s = dfs(1,1<<i)) break;
        }
        printf("Caso %d:", t);
        if(s) 
        {
            for(i=0;i<7;i++) printf(" %d", ord[i]);
            printf("\n");
        }
        else printf(" Sem solucao\n");
    }
    return 0;
}

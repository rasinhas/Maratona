#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, p;
    int cnt, i, j, err[1001], erro, cont[1001];
    int m[1001][6];
    string nome;
    map <string,int> id;
    while(scanf("%d%d", &k, &n) && k)
    {
        memset(cont,0,(n+1)*sizeof(int));
        id.clear();
        cnt = 1;
        for(i=0;i<n;i++)
        {
            cin >> nome;
            if(!id[nome]) id[nome] = cnt++;
            m[i][0] = id[nome];
            for(j=0;j<k;j++)
            {
                scanf("%d", &p);
                m[i][j+1] = p-1;
                cont[p-1]++;
            }
            sort(m[i]+1,m[i]+k+1);
        }
        memset(err,0,(n+1)*sizeof(int));
        for(i=0;i<n;i++)
        {
            if(m[i][0] == m[m[i][1]][0]) err[m[i][1]]++;
            for(j=2;j<=k;j++)
            {
                if(m[i][j] == m[i][j-1]) err[m[i][j-1]]++;
                if(m[i][0] == m[m[i][j]][0]) err[m[i][j]]++;
            }
            if(cont[i] < k) err[i]++;
        }
        for(i=0;i<=n;i++)
        {
            if(err[i]) erro++;
        }
        if(!erro) printf("NO PROBLEMS FOUND\n");
        else if(erro == 1) printf("1 PROBLEM FOUND\n");
        else printf("%d PROBLEMS FOUND\n", erro);
    }
    return 0;
}

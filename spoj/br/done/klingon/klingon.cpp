#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

typedef pair <int, int> pii;

int mod(int a){ return a > 0 ? a : -a; }

int escola[10000][1001];
int alunos[10000], ret[1001];

int main()
{
    int i, j, k, n, p, val, cnt;
    while(scanf("%d", &n) && n)
    {
        for(i=0;i<n;i++) memset(escola[i],0,1001*sizeof(int));
        memset(alunos,0,n*sizeof(int));
        memset(ret,0,1001*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d", &k);
            alunos[i] = k;
            for(j=0;j<k;j++)
            {
                scanf("%d", &p);
                escola[i][p]++;
            }
        }
        for(i=0;i<n;i++)
        {
            cnt = 0;
            for(j=0;j<1001;j++)
            {
                cnt += escola[i][j];
                escola[i][j] = mod(alunos[i] - 2*cnt);
                ret[j] += escola[i][j];
            }
        }
        val = INF;
        for(i=0;i<1001;i++) val = min(val, ret[i]);
        printf("%d\n", val);
    }
	return 0;
}

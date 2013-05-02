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

int main()
{
    int N, i, M[10000][2], tam, ant, nov, v[10000];
    while(scanf("%d", &N) != EOF)
    {
        for(i=0;i<N;i++) scanf("%d", &v[i]);
        tam = 2;
        ant = 0;
        for(i=0;i<=N-2;i++) M[i][ant] = max(v[i], v[i+1]);
        while(tam != N)
        {
            tam+=2;
            nov = (ant + 1) % 2;
            for(i=0;i<=N-tam;i++) M[i][nov] = max(v[i] + min(M[i+2][ant], M[i+1][ant]), v[i+tam-1] + min(M[i][ant], M[i+1][ant]));
            ant = nov;
        }
        printf("%d\n", M[0][ant]);
    }
	return 0;
}

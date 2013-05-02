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

int f[13] = {-1, 306, 337, 0, 31, 61, 92, 122, 153, 184, 214, 245, 275};

int main()
{
    int n, i, ret, total, dia, mes, ano, a, b, c, d, dant, cons, consant;
    while(scanf("%d", &n) && n)
    {
        ret = total = 0;
        consant = 0;
        dant = -1;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d", &dia, &mes, &ano, &cons);
            if(mes <= 2) --ano;
            a = ano/4;
            b = ano/100;
            c = ano/400;
            d = dia + f[mes] + ano*365 + a - b + c;
            if(d == dant+1)
            {
                ret++;
                total += cons - consant;
            }
            dant = d;
            consant = cons;
        }
        printf("%d %d\n", ret, total);
    }
	return 0;
}

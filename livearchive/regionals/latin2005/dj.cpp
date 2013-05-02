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
    map <int,string> ind;
    int i, n, q, k, v, p, ret, j, l;
    long long sum, aux;
    string str;
    while(scanf("%d%d", &n, &q) && n)
    {
        ind.clear();
        for(i=0;i<n;i++)
        {
            cin >> str;
            ind[i] = str;
        }
        for(i=0;i<q;i++)
        {
            scanf("%d", &k);
            sum = 0;
            aux = 1;
            for(j=1;sum<k;j++)
            {
                aux *= n;
                sum += aux*j;
                if(sum >= k)
                {
                    p = k-(sum-(aux*j));
                    v = (p-1);
                    p = v%j;
                    v /= j;
                    for(l=0;l<=p;l++)
                    {
                        aux /= n;
                        ret = v/aux;
                        v -= ret*aux;
                    }
                    break;
                }
            }
            cout << ind[ret] << endl;
        }
        printf("\n");
    }
	return 0;
}

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

int main()
{
    int n, h, m, s;
    int i, entradas, saidas, inc, ince, in, ret;
    char t;
    vector <pair<pair<int,int>, pair<int,char> > > horas;
    while(scanf("%d", &n) && n)
    {
        saidas = entradas = inc = 0;
        ret = 0;
        inc = in = 0;
        horas.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d:%d:%d %c ", &h, &m, &s, &t);
            horas.push_back(make_pair(make_pair(h,m),make_pair(s,t)));
            if(t == 'E') entradas++;
            else if(t == 'S') saidas++;
        }
        ince = (n/2 - entradas);
        sort(horas.begin(), horas.end());
        for(i=0;i<horas.size();i++)
        {
            if(horas[i].second.second == 'E') in++;
            else if(horas[i].second.second == 'X') in--;
            else 
            {
                inc++;
                if(inc > ince) 
                {
                    in--;
                    inc--;
                }
            }
            if(in < 0)
            {
                inc--;
                ince--;
                in++;
            }
            ret = max(ret, in+inc);
        }
        printf("%d\n", ret);
    }
	return 0;
}

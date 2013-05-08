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
    int n, m, i, j, k, pos, soma, aux;
    string emotic[1010];
    string phr;
    vector <pair<int,int> > inter;
    pair <int,int> at;
    while(scanf("%d%d", &n, &m) && n)
    {
        soma = 0;
        for(i=0;i<n;i++) cin >> emotic[i];
        getc(stdin);
        for(i=0;i<m;i++)
        {
            inter.clear();
            getline(cin,phr);
            for(j=0;j<n;j++)
            {
                pos = 0;
                while((pos = phr.find(emotic[j],pos)) != string::npos)
                {
                    inter.push_back(make_pair(pos,pos+emotic[j].size()));
                    pos++;
                }
            }
            sort(inter.begin(),inter.end());
            if(inter.size() > 0)
            {
                at = inter[0];
                aux = 1;
                for(j=1;j<inter.size();j++)
                {
                    if(inter[j].first < at.second)
                    {
                        if(inter[j].second < at.second) at.second = inter[j].second;
                        at.first = inter[j].first;
                    }
                    else
                    {
                        at = inter[j];
                        aux++;
                    }
                }
                soma += aux;
            }
        }
        printf("%d\n", soma);
    }
	return 0;
}

#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool cmp(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b)
{
    return (a.second.first > b.second.first);
}

int main()
{
    int p, f, i, n, pmax, pos, flag=1;
    vector <pair<int,pair<int,int> > > trap;
    vector <pair<int,int> > sol;
    priority_queue <pair<int,int> > fila;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d", &p, &f);
        pmax += p;
        trap.push_back(make_pair(i,make_pair(f+p,p)));
    }
    sort(trap.begin(),trap.end(),cmp);
    pos = 0;
    for(i=0;i<n;i++)
    {
        while(pos<n && trap[pos].second.first >= pmax)
        {
            fila.push(make_pair(trap[pos].first,trap[pos].second.second));
            pos++;
        }
        if(fila.empty()) 
        {
            flag = 0;
            break;
        }
        sol.push_back(fila.top());
        fila.pop();
        pmax -= sol[i].second;
    }
    if(!flag) printf("IMPOSSIVEL\n");
    else 
    {
        for(i=0;i<n;i++) printf("%d\n", sol[i].first+1);
    }
    return 0;
}

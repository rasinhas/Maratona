#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector<int> pos;
vector<pair<int, int> > c;

int main()
{
    int n, m, l, i, num, flag;
    while(scanf("%d %d", &m, &l) && (m || l))
    {
        scanf("%d", &n);
        pos.clear();
        c.clear();
        for(i=0; i<n; i++)
        {
            scanf("%d", &num);    
            c.push_back(make_pair(num, i));
        }
        sort(c.begin(), c.end());
        flag=0;
        for(i=n-1; i>=0; i--)
        {
            if(m<=l)
            {
                if(m>=c[i].first)
                {
                    pos.push_back(c[i].second);
                    m-=c[i].first;
                }
                else
                {
                    if(l>=c[i].first)
                    {
                        l-=c[i].first;
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
            }
            else
            {
                if(l>=c[i].first)
                {
                    l-=c[i].first;
                }
                else
                {
                    if(m>=c[i].first)
                    {
                        pos.push_back(c[i].second);
                        m-=c[i].first;
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(flag) printf("Impossible to distribute\n");
        else
        {
            printf("%d", pos.size());
            sort(pos.begin(), pos.end());
            for(i=0;  i<pos.size(); i++) printf(" %d", pos[i]+1);
            printf("\n");
        }
    }
    return 0;    
}

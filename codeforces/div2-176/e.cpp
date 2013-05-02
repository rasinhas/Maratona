#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <stack>
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
int x[1010000], q[1010000];

int main()
{
    stack <pii> s;
    int n, t;
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &x[i]);
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%d", &q[i]);
        x[q[i]-1] *= -1;
    }
    reverse(x,x+n);
    if(n%2) printf("NO\n");
    else
    {
        for(int i=0;i<n;i++)
        {
            if(!s.empty())
            {
                if(s.top().first + x[i] == 0 && s.top().first < 0)
                {
                    s.pop();
                    continue;
                }
                if(s.top().first == x[i] && s.top().first > 0)
                {
                    x[s.top().second] *= -1;
                    s.pop();
                    continue;
                }
            }
            s.push(mp(x[i],i));
        }
        reverse(x,x+n);
        if(s.empty())
        {
            printf("YES\n%d", x[0]);
            for(int i=1;i<n;i++) printf(" %d",x[i]);
        }
        else printf("NO\n");
    }
    printf("\n");
    return 0;
}

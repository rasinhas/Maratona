#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;

// (x, y) -> (e, v)
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};
map <pii,pii> m[2];
map <pii,pii>::iterator it;

int main()
{
    int n, c, l, k;
    while(scanf("%d", &n) && n)
    {
        for(int i=0;i<n;i++)
        {
            cin >> l >> c;
            m[0][mp(l,c)] = mp(1,0); 
        }
        cin >> k;
        for(int i=0;i<k;i++)
        {
            for(it=m[i%2].begin();it!=m[i%2].end();it++)
            {
                if(it->second.first == 1)
                {
                    for(int j=0;j<8;j++)
                    {
                        int nl=it->first.first+dx[j], nc=it->first.second+dy[j];
                        pii np = mp(nl,nc);
                        if(!m[i%2].count(np)) m[i%2][np] = mp(0,1);
                        else m[i%2][np].second++;
                    }
                }
            }
            for(it=m[i%2].begin();it!=m[i%2].end();it++)
            {
                if(it->second.second == 3 || (it->second.second == 2 && it->second.first == 1))
                {
                    m[(i+1)%2][mp(it->first.first,it->first.second)] = mp(1,0);
                }
            }
            m[i%2].clear();
        }
        cout << m[k%2].size() << endl;
        for(it=m[k%2].begin();it!=m[k%2].end();it++)
            cout << it->first.first << " " << it->first.second << endl;
        m[k%2].clear();
    }
    return 0;
}

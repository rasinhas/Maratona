#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define EPS 1e-6
#define mp make_pair

using namespace std;

pair <int,pair<int,int> > circ[1111];
pair <int,int> ptos[2222];

int main()
{
    int n, m, c, k, x, y, r;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        int ret = 0;
        cin >> c >> k;
        for(int i=0;i<c;i++)
        {
            cin >> x >> y >> r;
            circ[i] = mp(r,mp(x,y));
        }
        for(int i=1;i<=n;i++)
        {
            int a=0;
            for(int j=0;j<c;j++)
            {
                double xc = circ[j].second.first;
                double yc = circ[j].second.second;
                double rc = circ[j].first;
                if(xc*xc >= (xc*xc - rc*rc + (yc-i)*(yc-i)))
                {
                    int x1 = max(1, (int)((xc - sqrt(xc*xc - (xc*xc - rc*rc + (yc-i)*(yc-i))))+1-EPS));
                    int x2 = min(m, (int)((xc + sqrt(xc*xc - (xc*xc - rc*rc + (yc-i)*(yc-i))))));
                    ptos[a++] = mp(x1,-1);
                    ptos[a++] = mp(x2,1);
                }
            }
            sort(ptos,ptos+a);
            int ac=0;
            int in=-1;
            for(int j=0;j<a;j++)
            {
                ac += (-1*ptos[j].second);
                if(ac == k && in == -1) in = ptos[j].first;
                if(ac < k && in != -1)
                {
                    ret += (ptos[j].first - in + 1);
                    in = -1;
                }
            }
        }
        cout << ret << endl;
    }
    return 0;
}

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
#define EPS 1e-10

using namespace std;

int gcd(int a, int b)
{
    return ((b) ? gcd(b,a%b) : a);
}

int mod(int a)
{
    return a < 0 ? -a : a;
}

pair <pair<double,int>,int> make(pair <int,int> p1, pair<int,int> p2)
{
    pair <pair<double,int>,int> piii;
    int d2, mdc, a, b, c;
    a = p1.second-p2.second;
    b = p2.first-p1.first;
    c = p1.first*p2.second-p1.second*p2.first;
    if(a < 0) 
    {
        a*=-1;
        b*=-1;
        c*=-1;
    }
    if(a == 0)
    {
        if(b < 0)
        {
            b*=-1;
            c*=-1;
        }
    }
    if(a == 0 || b == 0 || c == 0) mdc = 1;
    else mdc=gcd(gcd(mod(a),mod(b)),mod(c));
    d2 = (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
    piii = make_pair(make_pair(atan2(-a,b)+EPS,d2),c/mdc);
    return piii;
}

int main()
{
    int ret, i, j, n;
    int x, y;
    vector <pair<pair<double, int>, int> > retas;
    pair <pair<double, int>, int> val;
    pair <int,int> pontos[1001];
    scanf("%d", &n);
    for(i=0;i<n;i++) 
    {
        scanf("%d%d", &x, &y);
        pontos[i] = make_pair(x,y);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            val = make(pontos[i],pontos[j]);
            retas.push_back(val);
        }
    }
    sort(retas.begin(),retas.end());
    j = 0;
    int c = 0;
    ret = 0;
    for(i=1;i<retas.size();i++)
    {
        // coeficientes angulares iguais;
        if(fabs(retas[i].first.first-retas[i-1].first.first) < EPS)
        {
            // distancias iguais
            if(retas[i].first.second == retas[i-1].first.second)
            {
                if(retas[i].second == retas[i-1].second)  c++;
                else
                {
                    ret -= ((c+1)*(c))/2;
                    c = 0;
                }
                j++;
            }
            else
            {
                ret += ((j+1)*(j))/2; 
                ret -= ((c+1)*(c))/2;
                j = 0;
                c = 0;
            }
        }
        else
        {
            ret += ((j+1)*(j))/2; 
            ret -= ((c+1)*(c))/2;
            j = 0;
            c = 0;
        }
    }
    ret += ((j+1)*(j))/2;
    ret -= ((c+1)*(c))/2;
    printf("%d\n", ret/2);
	return 0;
}

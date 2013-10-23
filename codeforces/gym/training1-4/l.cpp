#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

string s, a;
int p[33], f[33], v[33];
int c;
vector <int> cyc;
vector <pair<int,int> > cycles;

int gcd(int a, int b) { return b ? gcd(b,a%b) : a; }
int lcm(int a, int b) { return (a*b)/gcd(a,b); }

void dfs(int u)
{
    v[u] = c; 
    cyc.push_back(u);
    if(!v[p[u]]) dfs(p[u]);
}

void find(int u)
{
    dfs(u);
    int sz = cyc.size();  
    int ok;
    int mi=0, ml=1000;
    for(int i=0;i<sz;i++)
    {
        ok = 1;
        for(int j=0;j<cycles.size();j++)
        {
            int d = gcd(cycles[j].first,gcd(sz,cycles[j].second));
            if(i%d != 0) ok = 0;
            d = gcd(cycles[j].first,gcd(sz,i));
            if(cycles[j].second%d != 0) ok = 0;
            if((cycles[j].second-i)%gcd(sz,cycles[j].first) != 0) ok = 0;
        }
        if(ok && cyc[i%sz] < ml)
        {
            ml = cyc[i];
            mi = i;
        }
    }
    cycles.push_back(make_pair(sz,mi));
    for(int i=0;i<sz;i++)
    {
        f[cyc[i]] = cyc[mi];
        mi = (mi+1)%sz;
    }
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n >> s >> a;
        cycles.clear();
        memset(v,0,sizeof(v));
        c = 1;
        for(int i=0;i<26;i++) f[i] = -1;
        for(int i=0;i<a.size();i++) p[i] = a[i]-'a';
        for(int i=0;i<s.size();i++)
        {
            if(f[s[i]-'a'] == -1)
            {
                find(s[i]-'a');
                c++;
            }
            s[i] = 'a' + f[s[i]-'a'];
            cyc.clear();
        }
        cout << s << endl;
    }
    return 0;
}

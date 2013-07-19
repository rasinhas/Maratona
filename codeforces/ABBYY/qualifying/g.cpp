#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#define sz size()

using namespace std;

string p[11], str;
int l[11], r[11];
int n;
set <string> S;

int f[500];

void build_ff(string &p)
{
    f[0] = -1;
    for(int i=0;i<p.sz;i++)
    {
        f[i+1] = f[i]+1;
        while(f[i+1] > 0 && p[i] != p[f[i+1]-1]) f[i+1] = f[f[i+1]-1]+1;
    }
}

int kmp(string &s, string &p)
{
    build_ff(p);
    int occ=0, j=0;
    for(int i=0;i<s.sz;i++) while(1)
    {
        if(s[i] == p[j])
        {
            if(++j == p.sz)
            {
                occ++;
                j = f[j];
            }
            break;
        }
        if(j == 0) break;
        j = f[j];
    }
    return occ;
}

bool check(string &s)
{
    int occ=0;
    for(int i=0;i<n;i++)
    {
        occ = kmp(p[i],s);
        if(occ < l[i] || occ > r[i]) return false;
    }
    return true;
}

int main()
{
    int ret=0;
    string sub;
    cin >> str;
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i] >> l[i] >> r[i];
    for(int i=0;i<str.sz;i++)
    {
        for(int j=1;j<=(str.sz-i);j++)
        {
            sub = str.substr(i,j);
            if(check(sub)) S.insert(sub);
        }
    }
    cout << S.sz << endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#define pb push_back
#define sz size()

using namespace std;

set <vector <int> > vis;
char op[4] = {'+', '-', '*', '/'};

int oper(int a, int b, int i)
{
    if(i == 0) return a+b;
    else if(i == 1) return a-b;
    else if(i == 2) return a*b;
    if(a%b == 0) return a/b;
    else return -1;
}

void go(vector <int> h, int tar, string bt)
{
    for(int i=0;i<h.sz;i++)
    {
        for(int j=0;j<h.sz;j++)
        {
            vector <int> v;
            for(int k=0;k<h.sz;k++) if(k != i && k != j) v.pb(h[k]);
            for(int k=0;k<4;k++) 
            {
                int val = oper(h[i],h[j],k);
                v.pb(val);
                string s = "";
                s += h[i] + op[k] + h[j] + '=' + val;
                go(v,tar,bt+s);
                v.pop_back();
            }
        }
    }
}

int main()
{
    int t, n;
    int a;
    vector <int> h;
    cin >> t;
    while(t--)
    {
        for(int i=0;i<6;i++) 
        {
            cin >> a;
            h.pb(a);
        }
        cin >> n;
        go(h,n,"");
        vis.clear();
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int g[3333333][2];
int estados;
void init() 
{
    for(int j=0;j<2;j++) g[0][j] = -1;
    estados = 1;
}
void add(int n) 
{
    int e = 0;
    for(int i=30;i>=0;i--)
    {
        int next = ((n&(1<<i)) > 0);
        if (g[e][next] == -1) {
            g[e][next] = estados;
            for(int j=0;j<2;j++) g[estados][j] = -1;
            estados++;
        }
        e = g[e][next];
    }
}

int find(int n)
{
    int no = (INT_MAX^n);
    int ret = 0;
    int e = 0;
    for(int i=30;i>=0;i--)
    {
        int next = ((no&(1<<i)) > 0);
        if(g[e][next] != -1) 
        {
            e = g[e][next];
            ret += (1<<i);
        }
        else e = g[e][1-next];
    }
    return ret;
}

int main()
{
    int n, t, s, a;
    cin >> t;
    while(t--)
    {
        int m = 0;
        init();
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            if(i) s = s^a;
            else s = a;
            m = max(m,s);
            add(s);
            m = max(m,find(s));
        }
        cout << m << endl;
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
#define sz size()

using namespace std;

int main()
{
    int n, t, w, tt, tw, rt, rw, ret;
    vector <int>  b[2];
    scanf("%d", &n);
    tt = 0;
    tw = 0;
    for(int i=0;i<n;i++) 
    {
        scanf("%d%d", &t, &w);
        if(t == 1) b[1].pb(w);
        else b[0].pb(w);
        tt += t;
    }
    sort(b[0].begin(),b[0].end());
    sort(b[1].begin(),b[1].end());
    ret = tt;
    for(int i=0;i<=b[0].sz;i++)
    {
        if(tt >= tw) ret = min(ret,tt);
        rt = tt;
        rw = tw;
        for(int j=1;j<=b[1].sz;j++)
        {
            rt -= 1;
            rw += b[1][j-1];
            if(rw > rt) break;
            ret = min(ret,rt);
        }
        tt -= 2;
        if(i < b[0].sz) tw += b[0][i];
    }
    printf("%d\n", ret);
    return 0;
}

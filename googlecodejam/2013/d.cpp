#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define sz size()
#define pb push_back

using namespace std;

vector <int> kopens; //key that open chest i
vector <int> copen[210]; //chests opened by key i
vector <int> haskey[210]; //keys contained in chest i
vector <int> vis;

int dfs(int t, vector <int> canopen, vector <int> pai)
{
    int v=0, ret;
    vector <int> canstillopen;
    for(int i=0;i<haskey[t].sz;i++) 
    {
        for(int j=0;j<copen[haskey[t][i]].sz;j++)
        {
            canopen[copen[haskey[t][i]][j]]++;
        }
    }
    for(int i=0;i<canopen.sz;i++)
    {
        canstillopen = canopen;
        if(pai[i] == -1)
        {
            v++;
            if(canopen[i] > 0)
            {
                pai[i] = t;
                for(int j=0;j<copen[kopens[i]].sz;j++) canopen[j]--;
                ret = dfs(i,canstillopen,pai);
                for(int j=0;j<copen[kopens[i]].sz;j++) canopen[j]++;
                if(ret != -1) return ret;
                pai[i] = -1;
            }
        }
    }
    if(!v)
    {
        vis = pai;
        return t;
    }
    return -1;
}

int main()
{
    int T, n, k, ko, kn, ki, ky, x, ret;
    int start[200];
    vector <int> pai;
    vector <int> canopen; //times i can open each chest
    vector <int> vec;
    scanf("%d", &T);
    for(int t=0;t<T;t++)
    {
        scanf("%d%d", &k, &n);
        for(int i=0;i<k;i++) scanf("%d", &start[i]);
        for(int i=0;i<n;i++) 
        {
            scanf("%d%d", &ko, &kn);
            ko--;
            kopens.pb(ko);
            copen[ko].pb(i);
            for(int j=0;j<kn;j++)
            {
                scanf("%d", &x);
                x--;
                haskey[i].pb(x);
            }
            canopen.pb(0);
            pai.pb(-1);
        }
        for(int i=0;i<k;i++)
        {
            start[i]--;
            ky = start[i];
            for(int j=0;j<copen[ky].sz;j++) canopen[copen[ky][j]]++;
        }
        ret = -1;
        for(int i=0;i<n;i++)
        {
            if(canopen[i])
            {
                pai[i] = i;
                for(int j=0;j<copen[kopens[i]].sz;j++) canopen[j]--;
                ret = dfs(i,canopen,pai);
                for(int j=0;j<copen[kopens[i]].sz;j++) canopen[j]++;
                pai[i] = -1;
                if(ret != -1) break;
            }
        }
        printf("Case #%d:", t+1);
        if(ret == -1) printf("IMPOSSIBLE");
        else
        {
            for(int i=0;i<n;i++)
            {
                vec.pb(ret+1);
                ret = vis[ret];
            }
            for(int i=n-1;i>=0;i--) printf(" %d", vec[i]);
        }
        printf("\n");
        vec.clear();
        pai.clear();
        canopen.clear();
        vis.clear();
        kopens.clear();
        for(int i=0;i<200;i++)
        {
            haskey[i].clear();
            copen[i].clear();
        }
    }
    //clear vectors//
    return 0;
}

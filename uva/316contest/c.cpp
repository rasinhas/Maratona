#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int aut[60000];
int pos[1000], wdiff[60000], sdiff[600000];
int funfa[100], p;
string alf, w, s;

void kmp()
{
    int m, k;
    m = (int)w.size()-1;
    aut[1] = 0;
    k = 0;
    for(int i=1;i<m;i++)
    {
        while(k>0 && wdiff[k] != wdiff[i]) k=aut[k-1];
        if(wdiff[k] == wdiff[i]) k++;
        aut[i]=k;
    }
}

void match()
{
    int m, n, q;
    n = (int)s.size()-1;
    m = (int)w.size()-1;
    q = 0;
    for(int i=0;i<n;i++)
    {
        while(q>0 && wdiff[q]!=sdiff[i]) q = aut[q-1];
        if(wdiff[q] == sdiff[i]) q++;
        if(q == m)
        {
            funfa[(p+pos[s[i+1]]-pos[w[q]])%p]++;
            q = aut[q];
        }
    }
}

int main()
{
    int n, ret, at;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        memset(funfa,0,sizeof(funfa));
        memset(pos,0,sizeof(pos));
        cin >> alf;
        cin >> w;
        cin >> s;
        ret = 0;
        p = alf.size();
        for(int j=0;j<(int)alf.size();j++) pos[(int)alf[j]] = j+1;
        at = 0;
        for(int j=0;j<(int)w.size()-1;j++) wdiff[j] = ((pos[(int)w[j+1]] - pos[(int)w[j]]+p)%p);
        for(int j=0;j<(int)s.size()-1;j++) sdiff[j] = ((pos[(int)s[j+1]] - pos[(int)s[j]]+p)%p);
        kmp();
        match();
        for(int j=0;j<p;j++)
        {
            if(funfa[j] == 1) ret++;
        }
        if(ret == 0) printf("no solution\n");
        else if(ret == 1) 
        {
            printf("unique:");
            for(int j=0;j<p;j++) if(funfa[j] == 1) printf(" %d\n", j);
        }
        else
        {
            printf("ambiguous:");
            for(int j=0;j<p;j++) if(funfa[j] == 1) printf(" %d", j);
            printf("\n");
        }
    }
    return 0;
}

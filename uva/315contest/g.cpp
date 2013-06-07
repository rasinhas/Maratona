#include <iostream>
#include <cstdio>

using namespace std;

int rc[50010], rr[50010], diag[100100], rac[50010], cac[50010];

// TODO
int main()
{
    int T, r, c, n, ret;
    int row, col;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        cin >> r >> c >> n;
        memset(rac,0,sizeof(rac));
        memset(cac,0,sizeof(cac));
        memset(diag,0,sizeof(diag));
        for(int i=0;i<n;i++)
        {
            cin >> rr[i] >> rc[i];
            rr[i]--; rc[i]--;
            rac[rr[i]]++;
            cac[rc[i]]++;
            diag[r-rr[i]+rc[i]-1] = 1;
        }
        for(int i=1;i<r;i++) rac[i] += rac[i-1];
        for(int i=1;i<c;i++) cac[i] += cac[i-1];
        ret = 0;
        int inc = 1;
        int cnt = 0;
        /*
        for(int i=0;i<r+c-1;i++)
        {
            cnt += inc;
            row = min(r+c-i-2,r-1);
            col = min(i,c-1);
            if(!diag[i]) ret += cnt - rac[row] - cac[col]; 
            cout << i << " -> " << row << " x " << col << endl;
            if(i == r-1) inc = -1;
        }
        */
        // counting marked
        //rows
        ret += rr[r-1]*c;
        //columns
        ret += rc[c-1]*r;
        //diagonals
        for(int i=0;i<r+c-1;i++)
        {
            cnt += inc;
            if(diag[i]) ret += cnt;
            if(i == r-1) inc = -1;
        }
        //row/col intersect
        ret -= rc[c-1]*rr[r-1];
        //row/diag intersect
        inc = 1;
        cnt = 0;
        for(int i=0;i<r+c-1;i++)
        {
            cnt += inc;
            if(diag[i]) ret += cnt;
            if(i == r-1) inc = -1;
        }
        printf("Case %d: %d\n", t, ret);
    }
    return 0;
}

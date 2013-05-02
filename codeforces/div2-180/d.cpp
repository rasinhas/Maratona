#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k, qa, qb, ma, mb;
    int pa[100100], pb[100100];
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) cin >> pa[i];
    for(int i=0;i<m;i++) cin >> pb[i];
    sort(pa,pa+n);
    sort(pb,pb+m);
    int i, j;
    i = n-1;
    j = m-1;
    while(i >= 0 && j >= 0)
    {
        if(pa[i] > pb[j]) break;
        if(pa[i] <= pb[j])
        {
            i--;
            j--;
        }
    }
    if((j < 0 && i >= 0) || (i >= 0 && pa[i] > pb[j])) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

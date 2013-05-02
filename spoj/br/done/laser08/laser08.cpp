#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, q, y1, y2, init, fin, i, x1, x2;
    vector <int> xi, xf;
    vector <int>::iterator lo, hi;
    scanf("%d%d", &n, &q);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        xi.push_back(min(x1,x2));
        xf.push_back(max(x1,x2));
    }
    sort(xi.begin(),xi.end());
    sort(xf.begin(),xf.end());
    for(i=0;i<q;i++)
    {
        scanf("%d%d", &init, &fin);
        lo = lower_bound(xi.begin(), xi.end(), init);
        hi = upper_bound(xf.begin(), xf.end(), fin);
        printf("%d\n", int((lo-xi.begin())+n-(hi-xf.begin())));
    }
    return 0;
}

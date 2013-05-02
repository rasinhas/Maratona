#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> ofertas;
    int n, ret, p, i;
    while(scanf("%d", &n) && n)
    {
        ret = 0;
        ofertas.clear();
        for(i=0;i<n;i++) 
        {
            scanf("%d", &p);
            ofertas.push_back(p);
        }
        sort(ofertas.begin(),ofertas.end());
        for(i=0;i<n/2;i++) ret = max(ret,ofertas[i]+ofertas[n-i-1]);
        printf("%d\n",ret);
    }
    return 0;
}
